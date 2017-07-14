#! /bin/bash

cd dpci_install_3.1.1.572_release_linux_x86_64
usuario=$(who -q | grep -v =)

if [ $? == 1 ];then
	./install -q
	if [ $? != 0 ];then
		echo "Ocurrio un error al tratar de instalar dpci"
	fi
else
	echo "Error: No existe el directorio dpci"
fi
cd ..

instalar_libreria(){
	cd $1
	if [ $? == 0 ];then
		if [ ! -d build ];then
			mkdir build
		fi
	
		cd build
		cmake ..

		if [ $? == 0 ];then
			make && make install
			if [ $? != 0 ];then
				echo -e "\033[0;31mOcurrio un error al tratar de instalar" $1
				echo -e "\033[0m"
				cd ../..
				return 1
			fi
		else
			echo -e "\033[0;31mOcurrio un error al tratar de configurar" $1
			echo -e "\033[0m"
			cd ../..
			return 1
		fi

		cd ..
	fi

	chown -R $usuario build
	cd ..
	return 0
}

instalar_libreria newDigitalioLib
instalar_libreria newEngine_sv
instalar_libreria ID003_Lib_V3
instalar_libreria cmakeFlappy

if [ ! -f $HOME/.config/autostart/flappyBird.desktop ];then
	cp ./flappyBird.desktop $HOME/.config/autostart/
	chown $usuario $HOME/.config/autostart/flappyBird.desktop
fi

if [ ! -d $HOME/.config/flappyBird ];then
	mkdir $HOME/.config/flappyBird
	chown -R $usuario $HOME/.config/flappyBird
fi

if [ ! -d $HOME/.config/flappyBird/resource ];then
	cp -r ./cmakeFlappy/resource $HOME/.config/flappyBird
	chown -R $usuario $HOME/.config/flappyBird/resource
fi

if [ ! -f $HOME/.config/flappyBird/config.conf ];then
	cp -r ./cmakeFlappy/config.conf $HOME/.config/flappyBird
	chown  $usuario $HOME/.config/flappyBird/config.conf
fi

if [ ! -f /usr/local/bin/cambiarPropietarioPines.sh ];then
	cp ./cambiarPropietarioPines.sh /usr/local/bin/
fi

if [ ! -f /etc/systemd/system/cambiarPropietarioPines.service ];then
       cp ./cambiarPropietarioPines.service /etc/systemd/system/
fi       

systemctl enable cambiarPropietarioPines.service
