#!/bin/bash

sleep 20
ls -all /dev/ > $HOME/logsInicio

chown smart /dev/dpci0
chown smart /dev/ttyS0

ls -all /dev/ > $HOME/logsInicio2
