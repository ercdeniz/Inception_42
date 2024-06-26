all:
	@mkdir -p /home/ercdeniz/data/wordpress
	@mkdir -p /home/ercdeniz/data/mariadb
	@docker-compose -f srcs/docker-compose.yml up --build -d

start:
	@docker-compose -f srcs/docker-compose.yml start

stop:
	@docker-compose -f srcs/docker-compose.yml stop

clean:
	@docker-compose -f srcs/docker-compose.yml down --volumes

fclean: clean
	@docker system prune -af
	@rm -rf /home/ercdeniz/data

.PHONY: all start stop clean fclean
