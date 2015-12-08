# Ansible role `Monit`
Installs Monit for system monitoring and error recovery.

An Ansible role for installing `Monit` on RHEL/CentOS 7. Specifically, the responsibilities of this role are to:

- Install Role version 5.15
- Configure the config file for all the services you want to monitor on the host

## What is Monit?
Monit is a utility for managing and monitoring processes, programs, files, directories and filesystems on a Unix system. Monit conducts automatic maintenance and repair and can execute meaningful causal actions in error situations. E.g. Monit can start a process if it does not run, restart a process if it does not respond and stop a process if it uses too much resources. You can use Monit to monitor files, directories and filesystems for changes, such as timestamps changes, checksum changes or size changes.

Monit is controlled via an easy to configure control file based on a free-format, token-oriented syntax. Monit logs to syslog or to its own log file and notifies you about error conditions via customisable alert messages. Monit can perform various TCP/IP network checks, protocol checks and can utilise SSL for such checks. Monit provides a HTTP(S) interface and you may use a browser to access the Monit program.

Source: `https://mmonit.com/monit/documentation/monit.html`

## Monit's different services

- Proactive: It will act when an error situation should occur, the service will be restarted.
- Processes: U can monitor daemon processes or similar programs running on localhost.
- Files, dirs and filesystems: there's also a possibillity to monitor files, directories and filesystems. For example when there are changes. Or for security reasons.
- Cloud and Hosts: Monitor the network connections to various servers.
- Programs and scripts: test exit values of a program, or perform an action when there is an indication of an error.
- System: Monitor the general system resources, such as CPU usage, memory and load average.

## Getting started

- Download this role and copy it into `ansible/roles/`
- Make sure to set name `monit` under the server you are going to use for monitoring in file `ansible/site.yml`
- Vagrant up your server, and everything will be downloaded.
## Requirements

At this moment, we are using a vagrant-environment.
The role will be installed in the home directory of the vagrant-host.

U can find more info about how to use Vagrant here: `https://docs.vagrantup.com/v2/`

## Important files
### .monitrc
The role will be installed in the `/etc` directory of the vagrant host ( `home/etc/` ). If you use the `list -a` -command in this directory, you will notice a file called `.monitrc` .

In this file you got the opportunity to edit the settings of Monit server. All the lines with an  `#` before it are still in comment.
The user itself can put out of comment the options he want.
Right now we have the `set alert <e-mailadres>` out of comment already.
You can edit this file locally, and then `vagrant provision <name>` to make sure the changes are also done on the server. 
Here is a list of all the services you can use to monitor a server with Monit.

##Services

#### System information  (default)
	check system $HOST
	if loadavg (1min) > 4 then alert
    if loadavg (5min) > 2 then alert
    if cpu usage > 95% for 10 cycles then alert
    if memory usage > 15% then alert
    if swap usage > 25% then alert

#### Check if a file exists, checksum, permissions, uid and gid (optional)
	check file apache_bin with path /usr/local/apache/bin/httpd
	if failed checksum and
    expect the sum 8f7f419955cefa0b33a2ba316cba3659 then unmonitor
	if failed permission 755 then unmonitor
    if failed uid root then unmonitor
    if failed gid root then unmonitor
    if failed gid root then unmonitor
    alert security@foo.bar on {
           checksum, permission, uid, gid, unmonitor
       } with the mail-format { subject: Alarm! }
    group server

#### Check or a process is running: example Apache (optional)
	check process apache with pidfile /usr/local/apache/logs/httpd.pid
    start program = "/etc/init.d/httpd start" with timeout 60 seconds
    stop program  = "/etc/init.d/httpd stop"
    if cpu > 60% for 2 cycles then alert
    if cpu > 80% for 5 cycles then restart
    if totalmem > 200.0 MB for 5 cycles then restart
    if children > 250 then restart
    if loadavg(5min) greater than 10 for 8 cycles then stop
    if failed host www.tildeslash.com port 80 protocol http
       and request "/somefile.html"
    then restart
    if failed port 443 type tcpssl protocol http
       with timeout 15 seconds
    then restart
    if 3 restarts within 5 cycles then unmonitor
    depends on apache_bin
    group server

#### Check file-systems permissions, uid, gid, space and inode usage (optional)
	check filesystem datafs with path /dev/sdb1
    start program  = "/bin/mount /data"
    stop program  = "/bin/umount /data"
    if failed permission 660 then unmonitor
    if failed uid root then unmonitor
    if failed gid disk then unmonitor
    if space usage > 80% for 5 times within 15 cycles then alert
    if space usage > 99% then stop
    if inode usage > 30000 then alert
    if inode usage > 99% then stop
    group server

#### Check directory permissions, uid and gid (optional)
	check directory bin with path /bin
    if failed permission 755 then unmonitor
    if failed uid 0 then unmonitor
    if failed gid 0 then unmonitor

#### Check a file's timestamp (optional)
	check file database with path /data/mydatabase.db
    if failed permission 700 then alert
    if failed uid data then alert
    if failed gid data then alert
    if timestamp > 15 minutes then alert
    if size > 100 MB then exec "/my/cleanup/script" as uid dba and gid dba

#### Check a remote host availability by issuing a ping test and check the content of a response from a web server. (DEFAULT)
	check host <name> with address <ip-address>
    if failed url <ip-address>
	timeout 10 seconds for 1 cycles then alert
	then alert

#### Check network link status (up/down), link capacity changes, saturation and bandwith usage. (DEFAULT)
	check network public with interface eth0
    if failed link then alert
    if changed link then alert
    if saturation > 90% then alert
    if download > 10 MB/s then alert
    if total upload > 1 GB in last hour then alert

#### Check custom program status output (optional)
	check program myscript with path /usr/local/bin/myscript.sh
    if status != 0 then alert

##Includes
It's also possible to configure extra additional parts from other files or directories. You can set the files in `/etc/monit.d/*`

NOTE: Don't forget to put `include /etc/monit.d/*` inside the monitrc file if you want this to work.

### Log-file


## Contributing


## License

BSD

## Author Information

Daan Van Hecke
