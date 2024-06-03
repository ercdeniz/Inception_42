#!/bin/bash

echo "server {
		listen 443 ssl;
		listen [::]:443 ssl;
		server_name $DOMAIN_NAME; 
		ssl_certificate $CERTIFICICATES_OUT; 
		ssl_certificate_key $CERTIFICICATES_KEYOUT; 
		ssl_protocols TLSv1.3; 
		root /var/www/html;
		index index.php;
			location / {' 
					try_files $uri $uri/ =404;' 
			}' 
		location ~ \.php$ { 
			include snippets/fastcgi-php.conf; 
			fastcgi_pass $MYSQL_DATABASE_NAME:9000;
			proxy_connect_timeout 300s; 
			proxy_send_timeout 300s; 
			proxy_read_timeout 300s;
			fastcgi_send_timeout 300s;
			fastcgi_read_timeout 300s;
		}
}" | tee /etc/nginx/sites-enabled/default srcs/requirements/nginx/conf/default

if [ ! -f $CERTIFICATES_OUT ]; then
	openssl req \
	-newkey rsa:2048 \
	-nodes \
	-keyout $CERTIFICATES_KEYOUT \
	-x509 \
	-days 365 \
	-out $CERTIFICATES_OUT \
	-subj "/C=TR/ST=KOCAELI/L=GEBZE/O=42Kocaeli/CN=$DOMAIN_NAME";
fi

exec "$@"