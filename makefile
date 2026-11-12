printColor = @./bin/app_cor

all: clean tads exec

clean:
	${printColor} "Excluindo os arquivos intermediários" RED
	rm -f ./obj/data.o
	rm -f ./obj/hora.o
	rm -f ./obj/dataHora.o
	@echo 
	${printColor} "Excluindo os arquivos executáveis" RED
	rm -f ./bin/app_dataHora
	rm -f ./src/debug/app_dataHora
	rm -f ./src/debug/app_dataHora_completo
	@echo
tads:
	${printColor} "Compilando os tipos abstratos de dados" GY
	gcc -c ./src/data.c -I ./include/ -o ./obj/data.o
	gcc -c ./src/hora.c -I ./include/ -o ./obj/hora.o
	gcc -c ./src/dataHora.c -I ./include/ -o ./obj/dataHora.o
	@echo
exec:
	${printColor} "Compilando as aplicações e gerando os executáveis" GY 
	gcc ./apps/app_dataHora.c ./obj/* -I ./include/ -o ./bin/app_dataHora -fsanitize=undefined
	@echo
run:
	${printColor} "Rodando código" G
	./bin/app_dataHora
_debug_tads:
	${printColor} "Compilando a aplicação e gerando o executável com opção de depuração" GY
	gcc -g ./apps/app_dataHora.c ./obj/* -I ./include/ -o ./src/debug/app_dataHora -fsanitize=undefined
	@echo
_debug_all:
	${printColor} "Compilando a aplicação e gerando o executável com opção de depuração completa" GY 
	gcc -g ./apps/app_dataHora.c ./obj/ec_rgb_colors.o ./src/data.c ./src/hora.c ./src/dataHora.c -I ./include/ -o ./src/debug/app_dataHora_completo -fsanitize=undefined
	@echo
debug_tads:
	gdb ./src/debug/app_dataHora
debug_all:
	gdb ./src/debug/app_dataHora_completo
	