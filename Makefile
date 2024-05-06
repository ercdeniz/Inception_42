all:
	mkdir -p /home/ercdeniz/data /home/ercdeniz/data/mysql /home/ercdeniz/data/wordpress
	docker-compose -f ./srcs/docker-compose.yml up --build -d
down:
	docker-compose -f ./srcs/docker-compose.yml down
clean: down
	docker system prune -a
	docker volume rm $$(docker volume ls -q)
	rm -rf /home/ercdeniz/data
	rm -rf srcs/.env
re: clean all
.PHONY: all down clean re
