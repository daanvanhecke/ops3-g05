# Ansible role `Monit`
Installs Monit for system monitoring and error recovery.

An Ansible role for installing `Monit` on RHEL/CentOS 7. Specifically, the responsibilities of this role are to:

- Install Role version 5.15
- Configure the config file to your host that you want to monitor.

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


| Service   								  | Command					  |
| :---                                        | :---                      |
| System information | check system $HOST

	if loadavg (1min) > 4 then alert
    if loadavg (5min) > 2 then alert
    if cpu usage > 95% for 10 cycles then alert
    if memory usage > 15% then alert
    if swap usage > 25% then alert
|



### Log-file





## Contributing

Mathias Van Rumst


## License

BSD

## Author Information

Daan Van Hecke
