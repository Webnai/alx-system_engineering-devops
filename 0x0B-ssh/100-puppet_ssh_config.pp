#!/usr/bin/env bash
# using puppet to make changes to our configuration file

file { 'etc/ssh/ssh_config':
	ensure => present,
content =>"
	#SSH CLIENT CONFIGURATION
	host*
	IdentityFile ~/.ssh/school
	PasswordAuthentication no
}
