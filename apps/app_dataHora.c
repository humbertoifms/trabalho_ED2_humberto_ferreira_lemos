#include <stdio.h>
#include <stdlib.h>

#include "dataHora.h"
#include "hora.h"
#include "data.h"

int main(){
  struct DataHora *dataPrograma = dataHora_criar(3, 11, 2006, 10, 30, 26);
  struct DataHora *dataUsuario = dataHora_criar(1, 1, 1, 0, 0, 0);
  dataHora_ler(dataUsuario);

  printf("Maior dataHora: ");
  if(dataHora_comparar(dataPrograma, dataUsuario) == 1) dataHora_imprimir(dataPrograma);
  else if(dataHora_comparar(dataPrograma, dataUsuario) == -1) dataHora_imprimir(dataUsuario);
  else dataHora_imprimir(dataPrograma);

  dataHora_definir(dataUsuario, 10, 11, 2012, 13, 14, 15);
  printf("dataHora definida: %s\n", dataHora_obter_texto(dataUsuario));

  dataHora_inicializar(dataPrograma);
  printf("dataHora inicializada: %s\n", dataHora_obter_texto(dataPrograma));

  dataHora_desalocar(dataPrograma);
  dataHora_desalocar(dataUsuario);
  return 0;
}