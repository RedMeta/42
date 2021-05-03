#Get debian image
FROM debian:buster

#Setta l'autoindex on/off
ENV AUTOINDEX=on

#Update system and install needed packages
RUN apt-get -y update                       
RUN apt-get -y install \
	nginx \
	mariadb-server \
	wget dialog apt-utils \
	php-fpm php-mysql \
	php php-cgi php-mysqli php-pear \
	php-mbstring php-gettext php-common php-phpseclib

EXPOSE 80 443