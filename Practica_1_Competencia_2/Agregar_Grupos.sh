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
   echo "Debe indicar el archivo del listado con nombres de grupos a ingresar"
   exit 1
fi

# Del archivo con el listado de grupos a crear:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = group_name

crearGrupo(){
	#echo "----> Crear Grupo <----"
	eval group_name="$1"
	#echo "group_name 		  = ${group_name}"
	#echo "-------------------------"
	
	#-p, --password PASSWORD
    #Note: This option is not recommended because the password (or encrypted password) will be visible by users listing the processes.
    #You should make sure the password respects the system's password policy.
	
	if grep -q $group_name /etc/group;
	then
		echo "Ya existe un grupo con el nombre [${group_name}], no puede crear uno nuevo con el mismo nombre"
	else
		groupadd "${group_name}"
		if [ $? -eq $SUCCESS ];
		then
			echo "El grupo [${group_name}], se ha agregado correctamente"
		else
			echo "EL grupo [${group_name}], no se pudo agregar"
		fi
	fi
}

while IFS=: read -r f1
do
	crearGrupo "\${f1}"	
done < ${file}

exit 0