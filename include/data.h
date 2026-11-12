#ifndef DATA_H
#define DATA_H
  struct Data;

  // Criar datas
  struct Data * data_criar(int dd, int mm, int aa);
  struct Data * data_nova();

  // Manipular datas
  void data_inicializar(struct Data *data);
  void data_desalocar(struct Data * data);
  void data_definir_dia(struct Data * data, int dd);
  void data_definir_mes(struct Data * data, int mm);
  void data_definir_ano(struct Data * data, int aa);
  void data_definir(struct Data * data, int dd, int mm, int aa);

  // Obter datas  
  void data_ler(struct Data * data);
  int data_obter_dia(struct Data * data);
  int data_obter_mes(struct Data * data);
  int data_obter_ano(struct Data * data);
  char * data_obter_texto(struct Data * data);
  void data_imprimir(struct Data * data);
  
  // Comparar datas
  int data_comparar (const struct Data *d1, const struct Data *d2);
  struct Data * data_maior(const struct Data *d1, const struct Data *d2);
  struct Data * data_menor(const struct Data *d1, const struct Data *d2);
  void data_copiar(struct Data * origem, struct Data * destino);
#endif