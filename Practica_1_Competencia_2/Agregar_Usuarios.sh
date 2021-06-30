#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuario que desea crear"
   exit 1
fi

# Del archivo con el listado de usuario a crear:
# Este es el formato:
# ejemplo:pass:123:1001:EJEMPLO:/home/ejemplo:/bin/bash:
#    |      |   |    |     |          |           |   
#    f1     f2  f3   f4    f5         f6          f7
# f1 = nombre_usuario
# f2 = contrasena
# f3 = usuario_id
# f4 = grupo_id
# f5 = comentario
# f6 = directorio
# f7 = terminal_de_comandos_a_usar

agregarUsuario(){
	eval user="$f1"
	eval password="$f2"
	eval user_id="$f3"
	eval group_id="$f4"
	eval info="$f5"
	eval directory="$f6"
	eval terminal="$f7"
	
	if grep -q $user /etc/passwd ;
	then
		echo "Ya hay un usuario con el nombre [${user}], no puede crear uno con el mismo nombre"
	else
		if grep -q :x:$user_id /etc/passwd;
		then
			echo "Ya hay un usuario con el ID [${user_id}], no puede crear otro usuario con el mismo ID"
		else
			if grep -q $group_id /etc/group;
			then
				useradd -p ${password} -u ${user_id} -g ${group_id} -c ${info} -d ${directory} -m -s ${terminal} ${user}
				echo "$user:$password" | chpasswd --md5
				if [ $? -eq $SUCCESS ];
				then
					echo "El usuario [${user}], se ha agregado correctamente"
					chage -d0 ${user}
				else
					echo "El usuario [${user}], no se pudo agregar"
				fi
			else
				echo "No existe un grupo con ID [${group_id}]"
			fi
		fi
	fi
}

while IFS=: read -r f1 f2 f3 f4 f5 f6 f7
do
	agregarUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}" 
done < ${file}

exit 0
