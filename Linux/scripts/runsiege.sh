#!/bin/bash
function echocolor() { # $1 = string
    COLOR='\033[1;33m'
    NC='\033[0m'
    printf "${COLOR}$1${NC}\n"
}


echocolor "**********************"
echocolor "**  SIEGE TEST RUN  **"
echocolor "**********************"
echocolor "**********************"
echo 
echocolor "how many times would you like to run a test: "
read AANTALXTEST
echocolor "How long you want the test to run? (format: Number + S/M/H/D)"
read Twaarde
echocolor "Delay-value?: "
read Dwaarde
echocolor "How many concurring Users?"
read Cwaarde
echocolor "Name of the logfile"
read lognaam
echocolor "Clear originial logfile after test? (y / n)"
read clear
echo 
echo
echocolor "***********************"
echocolor "** PREPARING ENGAGE  **"
echocolor "***********************"
echo
echo gonna run:
echo siege -c$Cwaarde -d$Dwaarde -t$Twaarde
echo x $AANTALXTEST "times"
echo
echocolor "***********************"
echocolor "**      ENGAGING     **"
echocolor "***********************"

COUNTER=0
while [  $COUNTER -lt $AANTALXTEST ]; do
siege -c $Cwaarde -d $Dwaarde -t $Twaarde
let COUNTER=COUNTER+1 
 done
echo 
echo
echocolor "***********************"
echocolor "**   DONE ATTACKING  **"
echocolor "***********************"
echo
echo
echocolor "***********************"
echocolor "**MAKING CSV IN HOME **"
echocolor "***********************"
echo
echo Gonna run:
echo cp -r /usr/local/var/siege.log /home/fred/SiegeCSV/$lognaam.CSV
cp -r /usr/local/var/siege.log /home/fred/SiegeCSV/$lognaam.CSV
echo
echo
            if [ $clear = "y" ]; then
            	echo
				echocolor "***********************"
				echocolor "**Clearing log file  **"
				echocolor "***********************"
				echo
            	sudo bash -c 'echo "" > /usr/local/var/siege.log'
            else
                           	echo
				echocolor "*****************************"
				echocolor "**  NOT Clearing log file  **"
				echocolor "*****************************"
				echo
            fi

echocolor "****************************"
echocolor "**  Making Averages table **"
echocolor "****************************"
echo
echo Gonna run:
echo awk '{ total += $2; count++ } END { print total/count }' /home/fred/SiegeCSV/$lognaam.CSV

COUNTER=2
while [  $COUNTER -lt 11 ]; do
	
	if [ $COUNTER = 2 ]; then
			sudo bash -c 'echo -n "<td>" > /home/fred/SiegeCSV/'$lognaam'-averages.txt'
 			VAR=`awk '{ total += $2; count++ } END { print total/count }' /home/fred/SiegeCSV/$lognaam.CSV`
 			sudo bash -c 'echo -n '$VAR' >> /home/fred/SiegeCSV/'$lognaam'-averages.txt'
			sudo bash -c 'echo -n "</td>" >> /home/fred/SiegeCSV/'$lognaam'-averages.txt'
    else
    		sudo bash -c 'echo -n "<td>" >> /home/fred/SiegeCSV/'$lognaam'-averages.txt'
    		VAR=`awk '{ total += $'$COUNTER'; count++ } END { print total/count }' /home/fred/SiegeCSV/$lognaam.CSV`
    		sudo bash -c 'echo -n '$VAR' >> /home/fred/SiegeCSV/'$lognaam'-averages.txt'
			sudo bash -c 'echo -n "</td>" >> /home/fred/SiegeCSV/'$lognaam'-averages.txt'
    fi

let COUNTER=COUNTER+1 
 done

echocolor "***********************"
echocolor "**    DONE, HOORAY!  **"
echocolor "***********************"