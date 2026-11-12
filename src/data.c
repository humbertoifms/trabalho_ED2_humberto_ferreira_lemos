#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "ec_rgb_colors.h"

struct Data {
  int dd;
  int mm;
  int aa;
};

//==============================================================================================
// VALIDAÇÃO

int validaAA(int aa){
  if(aa > 0) 
    return 1;
  ec_imprimirCor("Ano invalido!\n", "RED");
  return 0;
}

int validaMM(int mm){
  if(mm > 0 && mm <= 12)
    return 1;
  ec_imprimirCor("Mes invalido!\n", "RED");
  return 0;
}

int validaDD(int dd){
  if(dd > 0 && dd <= 31)
    return 1;
  ec_imprimirCor("Dia invalido!\n", "RED");
  return 0;
}

int validaData(int dd, int mm, int aa){
  if(!validaDD(dd) || !validaMM(mm) || !validaAA(aa)){
    ec_imprimirCor("Data informada é invalida!\n", "RED");
    return 0;
  }
  return 1;
}

//==============================================================================================
// CRIAR DATAS

struct Data * data_criar(int dd, int mm, int aa){
  if(validaData(dd, mm, aa) == 0){
    return NULL;
  }
  struct Data * d;
  d = (struct Data *) malloc(1 * sizeof(struct Data));
  if(d == NULL){
    ec_imprimirCor("Não foi possivel alocar!\n", "RED");
    return NULL;
  }

  d->dd = dd;
  d->mm = mm;
  d->aa = aa;
}

struct Data * data_nova(){
  return data_criar(0, 0, 0);
}

//==============================================================================================
// MANIPULAR DATAS

void data_inicializar(struct Data *data){
  data->dd = 1;
  data->mm = 1;
  data->aa = 1;
}

void data_desalocar(struct Data *data){
  free(data);
}

void data_definir_dia(struct Data *data, int dd){
  if(validaDD(dd) == 0)
    data->dd = dd;
}

void data_definir_mes(struct Data *data, int mm){
  if(validaMM(mm) == 0)
    data->mm = mm;
}

void data_definir_ano(struct Data *data, int aa){
  if(validaAA(aa) == 0)
    data->aa = aa;
}

void data_definir(struct Data *data, int dd, int mm, int aa){
  if(validaData(dd, mm, aa) == 1){
    data->dd = dd;
    data->mm = mm;
    data->aa = aa;
  }
}

//==============================================================================================
// OBTER DATAS

void data_ler(struct Data *data){
  do{
    ec_imprimirCor("\nDados devem estar no padrão!\n", "GY");
    ec_imprimirCor("Insira o dia\n> ", "BLUE");
    scanf(" %d", &data->dd);
    ec_imprimirCor("Insira o mês:\n> ", "BLUE");
    scanf(" %d", &data->mm);
    ec_imprimirCor("Insira o ano:\n> ", "BLUE");
    scanf(" %d", &data->aa);
  }while(!validaData(data->dd, data->mm, data->aa));
}

int data_obter_dia(struct Data *data){
  return data->dd;
}

int data_obter_mes(struct Data *data){
  return data->mm;
}

int data_obter_ano(struct Data *data){
  return data->aa;
}

char * data_obter_texto(struct Data *data){
  char *text = malloc(11 * sizeof(char));
  if(text == NULL){
    ec_imprimirCor("Não foi possivel alocar!\n", "RED");
    return NULL;
  }
  sprintf(text, "%02d/%02d/%04d", data->dd, data->mm, data->aa);
  return text;
}

void data_imprimir(struct Data *data){
  printf("Data: %s\n", data_obter_texto(data));
}

//==============================================================================================
// COMPARAR DATAS

int data_comparar (const struct Data *d1, const struct Data *d2){
  if((d1->aa - d2->aa) < 0) return 1;
  if((d1->aa - d2->aa) > 0) return -1;
  if((d1->mm - d2->mm) < 0) return 1;
  if((d1->mm - d2->mm) > 0) return -1;
  if((d1->dd - d2->dd) < 0) return 1;
  if((d1->dd - d2->dd) > 0) return -1;
  return 0;
}

struct Data * data_maior(const struct Data *d1, const struct Data *d2){
  struct Data *d;
  if (data_comparar(d1, d2) == -1){
    d->aa = d2->aa;
    d->mm = d2->mm;
    d->dd = d2->dd;
  }else{
    d->aa = d1->aa;
    d->mm = d1->mm;
    d->dd = d1->dd;
  }
  if(data_comparar(d1, d2) == 1){
    d->aa = d1->aa;
    d->mm = d1->mm;
    d->dd = d1->dd;
  }

  return d;
}

struct Data * data_menor(const struct Data *d1, const struct Data *d2){
  struct Data *d;
  if (data_comparar(d1, d2) == 1){
    d->aa = d2->aa;
    d->mm = d2->mm;
    d->dd = d2->dd;
  }else{
    d->aa = d1->aa;
    d->mm = d1->mm;
    d->dd = d1->dd;
  }
  if(data_comparar(d1, d2) == -1){
    d->aa = d1->aa;
    d->mm = d1->mm;
    d->dd = d1->dd;
  }
  return d;
}

void data_copiar(struct Data *origem, struct Data *destino){
  destino->dd = origem->dd;
  destino->mm = origem->mm;
  destino->aa = origem->aa;
}