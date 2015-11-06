# $stack
## Opstelling
...

## Siege

The -d NUM option sets a random interval between 0 and NUM that each "user" will sleep for between requests. While the -c NUM option sets the concurrent number of simulated users.


open siege log : ```nano  ```

legende siege log: nano /usr/local/var/siege.log <br\>

|  Transactions | Elapsed Time  | Data Transferred | Response Time | Concurrency | Succesful Transactions | Failed Transactions    |
| ------------- |:-------------:| ----------------:| ------------- |:-----------:| ----------------------:| ----------------------:|

overeenkomstige Jmeter log:

|  #Samples | Elapsed Time  | Bytes | Response Time | Concurrency | Succesful Transactions | Failed Transactions    |
| ------------- |:-------------:| ----------------:| ------------- |:-----------:| ----------------------:| ----------------------:|


=> De tabel concurrency kunnen we eventueel laten vallen.
DOEL: Zowel siege als jmeter leveren een gelijkaardige CSV-file op. Op basis van dit maken we grafieken, gemiddelden,... .

pages under siege: ...

### siege -c5 -d10 -t5M
|               | img           |OK/NOK/OPM  |
| ------------- |:-------------:| ----------:|
| siege output  | ![]()         |            |
| collectd      | ![]()         |            |
|               | ![]()         |            |
|               | ![]()         |            |
|               | ![]()         |            |
|               | ![]()         |            |

opm:

### siege -c10 -d10 -t5M

### siege -c20 -d10 -t5M

### siege -c40 -d10 -t5M

### siege -c80 -d10 -t5M

### siege -c160 -d10 -t5M

## JMeter

## Algemene conclusie
