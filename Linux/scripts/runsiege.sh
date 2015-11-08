#!/bin/bash
function echocolor() { # $1 = string
    COLOR='\033[1;33m'
    NC='\033[0m'
    printf "${COLOR}$1${NC}\n"
}

echocolor "**************************************************************************"
echocolor "**                     SIEGE GRAPH GENERATOR                            **"
echocolor "**************************************************************************"
echo 
echo 
echocolor "**************************************************************************"
echocolor "**                          INITIALISATION                              **"
echocolor "**************************************************************************"
echo
echocolor "on wich numbers of concurring users you want to test (seperate with a space): "
read -a arr
echo 
echocolor "how many times would you like to run a single test (for each number of conurring users): "
read AANTALXTEST
echo
echocolor "How long you want a single test to run? (format: Number + S/M/H/D)"
read Twaarde
echo
echocolor "Delay-value?: "
read Dwaarde
echo
echocolor "Name of the CSV-ouputfile"
read lognaam
echo
echocolor "**************************************************************************"
echocolor "**                          CHECK TO CONTINUE                           **"
echocolor "**************************************************************************"
echo 
echocolor "check site for following concurring users:"
for a in ${arr[@]}
do 
  echo -n $a " "
done
echo
echo
echocolor "Time for a single test = " 
echo -n $Twaarde
echo
echocolor "Delay Time = " 
echo -n $Dwaarde
echo
echo
echocolor "continue? (type y / n)"
read checkers
if [ $checkers = "n" ]; then     
        exit    
fi

echo 
echocolor "**************************************************************************"
echocolor "**             TIME TO ENGAGE, LAY BACK, WATCH, RELAX!                  **"
echocolor "**************************************************************************"
echo
for b in ${arr[@]}
do 
echo 
echocolor "**************************************************************************"
echocolor "**        STARTING "$AANTALXTEST" ATTACKS WITH "$b" USERS               **"
echocolor "**************************************************************************"
echo 	

COUNTER=0
while [  $COUNTER -lt $AANTALXTEST ]; do
siege -c $b -d $Dwaarde -t $Twaarde
let COUNTER=COUNTER+1 
done

echo 
echocolor "**************************************************************************"
echocolor "**               ATTACKS FINISHED: MAKING TABLE ROW                     **"
echocolor "**************************************************************************"
echo 	
cp -r /usr/local/var/siege.log /home/fred/SiegeCSV/$lognaam.CSV
sudo bash -c 'echo "" > /usr/local/var/siege.log'

COUNTER=2
while [  $COUNTER -lt 11 ]; do
	
	if [ $COUNTER = 2 ]; then
			sudo bash -c 'echo -n "<td>" > /home/fred/SiegeCSV/'$lognaam'-'$b'.txt'
 			VAR=`cat /home/fred/SiegeCSV/$lognaam.CSV  | awk -F',' '{sum+=$"'"$COUNTER"'"; ++n} END { print sum/"'"$AANTALXTEST"'" }'`
 			sudo bash -c 'echo -n '$VAR' >> /home/fred/SiegeCSV/'$lognaam'-'$b'.txt'
			sudo bash -c 'echo -n "</td>" >> /home/fred/SiegeCSV/'$lognaam'-'$b'.txt'
    else
    		sudo bash -c 'echo -n "<td>" >> /home/fred/SiegeCSV/'$lognaam'-'$b'.txt'
            VAR=`cat /home/fred/SiegeCSV/$lognaam.CSV  | awk -F',' '{sum+=$"'"$COUNTER"'"; ++n} END { print sum/"'"$AANTALXTEST"'" }'`
    		sudo bash -c 'echo -n '$VAR' >> /home/fred/SiegeCSV/'$lognaam'-'$b'.txt'
			sudo bash -c 'echo -n "</td>" >> /home/fred/SiegeCSV/'$lognaam'-'$b'.txt'
    fi
let COUNTER=COUNTER+1 
 done
done

#Transactions | Elapsed Time  | Data Transferred | Response Time | Concurrency | Succesful Transactions | Failed Transactions 
echo "<table><tr><th> #Transactions </th><th> Elapsed Time </th><th> Data Transferred </th><th> Response Time </th><th> Concurrency </th><th> Succesful Transactions </th><th> Failed Transactions </th></tr>" > /home/fred/testtabel.txt
for c in ${arr[@]}
do 
 	sudo bash -c 'echo "<tr>" >> /home/fred/testtabel.txt'
 	sudo bash -c 'cat /home/fred/SiegeCSV/'$lognaam'-'$c'.txt >> /home/fred/testtabel.txt'
    sudo bash -c 'echo "</tr>" >> /home/fred/testtabel.txt'
    rm -f /home/fred/SiegeCSV/$lognaam-$c.txt
done
echo "</table>" >> /home/fred/testtabel.txt
rm -f /home/fred/SiegeCSV/$lognaam.CSV


echo 
echocolor "**************************************************************************"
echocolor "**                         DONE, HOORAY                                 **"
echocolor "**************************************************************************"
echo 