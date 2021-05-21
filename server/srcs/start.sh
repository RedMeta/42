#!/bin/bash

# Start up Ngnix
service nginx start;

# Start up MySQL
service mysql start;

# Start up PHP
service php7.3-fpm start;

#------------------------ Create & configure Wordpress database ----------------------------------------

# 1. Connect to MySQL using "root" account and create a database
echo "CREATE DATABASE wordpress;" | mysql -u root --skip-password;

# 2. Gives the user "root" all possible rights related to "wordpress" database
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost' WITH GRANT OPTION;" | mysql -u root --skip-password;

# 3. Apply the previous changes (otherwise it waits until we restart the server)
echo "FLUSH PRIVILEGES;" | mysql -u root --skip-password;

# 4. Disregards the password, check the UNIX socker instead
# Since we setup no password, it wouldn't let us connect to phpMyAdmin otherwise
echo "update mysql.user set plugin='' where user='root';" | mysql -u root --skip-password;

#------------------------------------------------------------------------------------------------------

# Restart php to apply the changes
service php7.3-fpm restart;

bash

