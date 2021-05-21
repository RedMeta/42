#Get debian image
FROM debian:buster

#Set autoindex on/off
ENV AUTOINDEX=on

#Update system and install needed packages
RUN apt-get -y update                       
RUN apt-get -y install \
	wget \
	nginx \
	mariadb-server \
	php-cgi php-mbstring php-fpm php-mysql php-xml
RUN mkdir /var/www/localhost

#Set Nginx
COPY srcs/localhost* /etc/nginx/sites-available
RUN ln -s /etc/nginx/sites-available/localhost_autoindx_on.conf /etc/nginx/sites-enabled
WORKDIR /var/www/localhost/

#Set PhpMyAdmin
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz
RUN tar -xvzf phpMyAdmin-5.1.0-english.tar.gz && rm -rf phpMyAdmin-5.1.0-english.tar.gz
RUN mv phpMyAdmin-5.1.0-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

#Set WordPress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz 
COPY ./srcs/wp-config.php /var/www/localhost/wordpress

#Copy final files
RUN mkdir ./utils
RUN mkdir ./s_files
COPY ./srcs/start.sh ./utils
COPY ./srcs/autoindex /bin
COPY ./srcs/error404.gif ./s_files

#Set File Permission
RUN chown -R www-data:www-data ./*
RUN chmod -R 755 ./*

RUN openssl req -x509 -nodes -days 30 -subj "/C=IT/ST=Italy/L=Rome/O=42 Network/OU=self/CN=asinamet" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

EXPOSE 80 443

CMD bash ./utils/start.sh