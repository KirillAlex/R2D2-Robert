# R2D2-Robert
Нашата цел беше да направим робот, който да помогне на инвалидите, които не могат да се движат, с него те могат да се "разхождат" по улиците.
kod za raspberry (terminal)
>wget https://github.com/danidomi/motion/releases/download/release/motion.zip
>unzip motion.zip
>cd mmal
>sudo apt-get install -y libjpeg-dev libavformat56 libavformat-dev libavcodec56 libavcodec-dev libavutil54 libavutil-dev libc6-dev zlib1g-dev libmysqlclient18 libmysqlclient-dev libpq5 libpq-dev
>sudo apt-get install nginx
>sudo apt-get install apache2-utils
>sudo htpasswd -c /home/pi/.htpasswd admin 
>sudo crontab -e 
*/1 * * * * pgrep motion || /home/pi/mmal/startmotion
sudo apt-get install nginx sudo apt-get install apache2-utils sudo htpasswd -c /home/pi/.htpasswd admin vi /etc/nginx/sites-available/default
location / {
                # First attempt to serve request as file, then
                # as directory, then fall back to displaying a 404.
                try_files $uri $uri/ =404;
                auth_basic “Restricted”;
                auth_basic_user_file /home/pi/.htpasswd;
                proxy_pass http://127.0.0.1:8081/img/video.mjpeg;
        }
>sudo service nginx start
>vi ~/updatedns.sh
#!/bin/sh
wget --no-check-certificate -O - https://freedns.afraid.org/dynamic/update.php?XXXXXXXXXXXXX >> /tmp/XXXXXXXXXXXXX.log 2>&1 &
https://play.google.com/store/apps/details?id=de.twolazy.monitor
