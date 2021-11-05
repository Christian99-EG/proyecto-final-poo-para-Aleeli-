/**
Proyecto AMSCHEL creado por el estudiante en ingenieria en
computacion Cristian Escalante Garcia
comenzando el dia miercoles 28 de abril del 2021
*/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <math.h>
#include <cstring>

using namespace std;

//creacion de la clase Modelo de costo lineal llamado MClineal
/**funciona para calcular el costo de produccion y de los ingresos totales
que se genera en la empresa*/

//inicio de la clase modelo de costo linal (MCLINEAL)
class MClineal{
protected:

  float *CTotal = new float; //costo total por toda la produccion

  float *CFinal = new float; //costo fijo por cada pieza del lote producido

  float *CVariable = new float; //variablilidad de costo de cada producto

  int CProduccion; //cuantos productos se van a producir q= catidad
public:
  MClineal();
  ~MClineal();
  void Pedir_dmclineal();
  float Operacion_mclineal(); //metodo que me calcula el modelo de costo lineal
  void Mostrar_mclineal();
};

MClineal::MClineal(){}//constructor de la clase MClineal

MClineal::~MClineal(){} //destructor de la clase MClineal

void MClineal::Pedir_dmclineal(){
  cout<<"Ingrese el costo variable: ";
  cin>>*CVariable;
  cout<<"Ingrese la cantidad de productos que va a producir:";
  cin>>CProduccion;
  cout<<"ingrese el costo final de su producto: ";
  cin>>*CFinal;
  cout<<endl;
}
float MClineal::Operacion_mclineal(){
  return *CTotal = (*CVariable * CProduccion) + *CFinal;
  delete CTotal;
  delete CVariable;
  delete CFinal;
}

void MClineal::Mostrar_mclineal(){
  cout<<"el costo total de tus productos es: "<<*CTotal<<endl;
}
//fin del contenido de la clase modelo de costo lineal

//inicio de la clase: Funcion de ingresos
class Funcion_ingresos{  //esta funcion me sirve para calcular los ingresos obtenidos en base
protected:
  float *Ingreso = new float;
  float *Precio_productos = new float;
  int *Cant_productos = new int;
public:
  Funcion_ingresos();
  ~Funcion_ingresos();
  void pedir_datosI();
  float Calcular_ingresos();
  void Mostrar_ingresos();
}; //fin de la clase funcion de ingresos

Funcion_ingresos::Funcion_ingresos(){} //constructor tratado como "por omision"
Funcion_ingresos::~Funcion_ingresos(){} //destructor //tratado como "por omision"

void Funcion_ingresos::pedir_datosI(){

  cout<<"Ingresa el precio de los productos: ";
  cin>>*Precio_productos;
  cout<<"ingresa la cantidad de productos que tienes: ";
  cin>>*Cant_productos;
  cout<<endl;

}
float Funcion_ingresos::Calcular_ingresos(){

return *Ingreso = *Precio_productos * *Cant_productos;
delete Ingreso;
delete Precio_productos;
delete Cant_productos;    //aqui te quedaste hoja 3
}
void Funcion_ingresos::Mostrar_ingresos(){
  cout<<"el ingreso que obtendras de tus productos es:"<<*Ingreso;
  cout<<"\n";
}
//final de el contenido de la clase funcion de ingresos

class Interes{   // clase base (padre) para los child -> "pagare"
protected:
  float Capital;
  float Tiempo;
  float mes;
  float anio;
  float Porcentaje_interes;
  int Interes_Final;
public:
  Interes();
  ~Interes();
virtual void Calcular_interes();
};

Interes::Interes(){}
Interes::~Interes(){}

void Interes::Calcular_interes(){

  cout<<"años en total:";
  cin>>anio;
  cout<<"\n";
  cout<<"meses en total:";
  cin>>mes;
  Tiempo = (anio * 12) + mes;
  cout<<"Total de tiempo expresado en meses: "<<Tiempo<<endl;
  cout<<"Capital transferido: ";
  cin>>Capital;
  cout<<"\n";
  cout<<"Porcentaje de interes establecido: ";
  cin>>Porcentaje_interes;
  cout<<"\n";
  Interes_Final = Capital* Porcentaje_interes *Tiempo;
  cout<<"El interes total es: "<<Interes_Final<<endl;
}

class MontoTotal:public Interes{  //suma de capital, mas los intereses generados a una tasa i% en un tiempo t// tambien se le conoce como valor futuro
protected:
  float Monto;
  float PorcentajeP;
public:
   MontoTotal();//metodo que nos determina el monto total mas los intereses generados a una tasa (%i) en un tiempo t
  ~MontoTotal();
virtual  void MontoT();
};

MontoTotal::MontoTotal():Interes(){}
MontoTotal::~MontoTotal(){}

void MontoTotal::MontoT(){
  cout<<"años en total:";
  cin>>anio;
  cout<<"\n";
  cout<<"meses en total: ";
  cin>>mes;
  Tiempo = anio + mes/12;
  cout<<"Capital inicial: ";
  cin>>Capital;
  cout<<"\n";
  cout<<"Porcentaje de interes establecido:";
  cin>>Porcentaje_interes;
  Porcentaje_interes = Porcentaje_interes / 100;
  Monto = Capital * (1 + (Porcentaje_interes * Tiempo));
  cout<<"\n";
  cout<<"Tiempo"<<Tiempo<<endl; //quitar este cout --> era solo de prueba para el programa verificado!
  cout<<"porcentaje"<<Porcentaje_interes<<endl;
  cout<<"El monto total de deuda/pago es:"<<Monto<<endl;
}

class Valor_actual:public MontoTotal{  //clase ya revisada lista para enviar a amschel que calcula el valor actual de un bien o un pagare que es simplemente el valor original por el cual se basa el monto, sin el interes generado por el monto
protected:
  float Tiempo_pactado;
  string Tiempo_establecido; //el tiempo en el que se fijo los pagos si son en dias o en meses
  string E_eng;
  string E_des;
  float porcentaje_enganche;
  float porcentaje_faltante;
  float enganche;
public:
  Valor_actual();
  ~Valor_actual();
  void Calcular_valorI();
};

Valor_actual::Valor_actual():MontoTotal(){}
Valor_actual::~Valor_actual(){}

void Valor_actual::Calcular_valorI(){
  cout<<"Cuando vence el pagare en meses/dias: ";
  cin>>Tiempo_establecido;

  if(Tiempo_establecido == "dias"){

    cout<<"\n"<<endl;
    cout<<"tiempo establecido en dias \n"<<endl;

    cout<<"digite los dias establecidos o faltantes para el pago:";
    cin>>Tiempo_pactado;
    Tiempo_pactado = Tiempo_pactado/360;
    cout<<endl;
    cout<<"digite el capital aportado:";
    cin>>Capital;
    cout<<endl;
    cout<<"tasa de interes: ";
    cin>>Porcentaje_interes;
    Porcentaje_interes = Porcentaje_interes / 100;
    cout<<endl;
    Monto = Capital / (1 + (Porcentaje_interes*Tiempo_pactado));


    cout<<"el valor actual de tu pagare es:"<<Monto<<endl;

  }if(Tiempo_establecido == "meses"){

    cout<<"tiempo establecido en meses"<<endl;

    cout<<"digite los meses establecido o faltantes para el pago:";
    cin>>Tiempo_pactado;
    Tiempo_pactado = Tiempo_pactado / 12;
    cout<<endl;
    cout<<"digite el capital aportado:";
    cin>>Capital;
    cout<<endl;
    cout<<"digite la tasa de interes:";
    cin>>Porcentaje_interes;
    Porcentaje_interes = Porcentaje_interes / 100;
    cout<<endl;

    Monto = Capital / (1 + (Porcentaje_interes*Tiempo_pactado));

    cout<<"el valor actual de tu pagare es:"<<Monto<<endl;


  }
  cout<<"\n"<<endl;
  cout<<"aporto un enganche a su pagare digite si/no, en caso de querer calcularlo:";
  cin>>E_eng;
  if(E_eng == "si"){

    cout<<"porcentaje de enganche:";
    cin>>porcentaje_enganche;
      porcentaje_enganche = porcentaje_enganche / 100;
    cout<<endl;
    cout<<"porcentaje faltante para pagar:";
    cin>>porcentaje_faltante;
    porcentaje_faltante = porcentaje_faltante / 100;
    cout<<endl;
    enganche = porcentaje_enganche*Monto / porcentaje_faltante;

    //cout<<"porcentaje enganche:"<<porcentaje_enganche<<endl; //quitar lineas 156-164
    //cout<<"monto:"<<Monto<<endl;
    //cout<<"porcentaje de interes:"<<Porcentaje_interes<<endl;
    cout<<"el enganche que usted pago/recibio fue: "<<enganche<<endl;
    cout<<endl;

    cout<<"enganche abonado: "<<enganche<<endl;
    cout<<"el costo total del pagare fue de:"<<Monto + enganche<<endl;

  }

  cout<<"Quiere calcular el descuento real que se le realizo, digite si/no: ";
  cin>>E_des;

  if(E_des == "si"){
    cout<<"el descuento real que se obtuvo fue de: "<<Capital - Monto<<"\n"<<endl;
  }
}

class DescuentoB:public MontoTotal{ //Descuento que se aplica a un bien ya sea bancario, comercial o monetario y que este a su vez repercute en lo que pagara el usuario final de su bien o producto
protected:
  float T_descuento;
public:
  DescuentoB();
  ~DescuentoB();
  void CalcularDescuento();
};

DescuentoB::DescuentoB():MontoTotal(){}
DescuentoB::~DescuentoB(){}

void DescuentoB::CalcularDescuento(){

  cout<<"Monto:";
  cin>>Monto;
  cout<<"\n";
  cout<<"tasa de descuento manejado:";
  cin>>PorcentajeP;
  PorcentajeP = PorcentajeP /100;
  cout<<"\n";
  cout<<"Tiempo que falta para el vencimiento (años): ";
  cin>>Tiempo;
  T_descuento = Monto * PorcentajeP * Tiempo;

  cout<<"El descuento bancario es de:"<<T_descuento<<endl;
}

class Inflacion: virtual public MontoTotal{ //calcula el poder economico de algun producto o su valor en el mercado, en cuanto a perdido o ganado ineteres comercial y cuanto va acumulando poder adquisitivo
float T_inflacion;
int n_mestral;
//string name_mestral
public:
  Inflacion();
  ~Inflacion();
  void MontoT();
};

Inflacion::Inflacion():MontoTotal(){}
Inflacion::~Inflacion(){}

void Inflacion::MontoT(){
  cout<<"ingrese el valor actual de la inflacion:";
  cin>>Capital;
  cout<<"En cuantos años quieres establecer la inflacion:";
  cin>>Tiempo;
  T_inflacion = Tiempo *4;
  cout<<"\n";
  cout<<"ingrese el porcentaje de interes sobre la inflacion: ";
  cin>>PorcentajeP;
  PorcentajeP = PorcentajeP / 100;
  cout<<"\n";
  Monto = Capital * (1 + (PorcentajeP*T_inflacion));
  cout<<"la inflacion de estima que sera de: "<<Monto<<" en un lapso de "<<Tiempo<<" años";
  cout<<"\n";
}

class helpme{
protected:
int opcionesAyuda;
public:
  helpme();
  ~helpme();
   void mostrar_ayuda();
  //void help_Modelocl();

};

helpme::helpme(){}
helpme::~helpme(){}

void helpme::mostrar_ayuda(){

  cout<<"A continuacion seleccione que de que tema quiere obtener ayuda: \n"<<endl;

  cout<<"[0] Introduccion a las finanzas (personales) en forma general \n"<<endl;
  cout<<"[1] MODELO DE COSTO LINEAL \n"<<endl;
  cout<<"[2] FUNCION DE INGRESOS \n"<<endl;
  cout<<"[3] INTERESES \n"<<endl;
  cout<<"[4] MONTO TOTAL (VALOR FUTURO) \n"<<endl;
  cout<<"[5] VALOR ACTUAL \n"<<endl;
  cout<<"[6] ENGANCHE \n"<<endl;
  cout<<"[7] DESCUENTO REAL \n"<<endl;
  cout<<"[8] DESCUENTO BANCARIO \n"<<endl;
  cout<<"[9] INFLACION \n"<<endl;
  //cout<<"[7] DESCUENTO BANCARIO \n"<<endl;

  cout<<"Su numero de opcion es:";
  cin>>opcionesAyuda;

  cout<<"\n"<<endl;

  switch (opcionesAyuda) {
    case 0:
    cout<<"Introduccion a las finanzas \n"<<endl;
    cout<<"Objetivo de las finanzas en forma general \n"<<endl;

    cout<<"si realizamos una analogía muy sencilla, las finanzas en una empresa o"<<endl;
    cout<<"negocio funcionan como un tablero de navegación Si una empresa o negocio"<<endl;
    cout<<"sin importar si es pequeña mediana o grande, cuenta con un buen tablero, el dueño"<<endl;
    cout<<"o director general podrá tomar buenas decisiones."<<endl;

    cout<<"\n"<<endl;

    cout<<"El objetivo de las finanzas en una empresa o negocio es que actúan como columna vertebral"<<endl;
    cout<<"de cualquier organizacion, es decir proporcionan informacion de forma veraz y oprtuna para"<<endl;
    cout<<"para que los dueños de sus negocios o empresas tomen buenas desiciones financieras."<<endl;
    cout<<"\n"<<endl;
    cout<<"¿Te imaginas que tu coche no tenga tablero con indicadores?"<<endl;
    cout<<"\n"<<endl;
    cout<<"Intenta pensar como averiguarias cuanta gasolina te queda o si tu coche esta en perfecto estado"<<endl;
    cout<<"Ahora imagina una organizacion como el area de finanzas o bine una mala admistracion de tu negocio"<<endl;
    cout<<"quebraria al instante"<<endl;

    cout<<"\n"<<endl;

    cout<<"Las finanzas existen en una empresa o negocio, para tomar decisiones, se necesita estos conceptos"<<endl;
    cout<<"o pilares que mencionaremos mas adelante."<<endl;
    cout<<"\n"<<endl;

    cout<<"Área fiscal"<<endl;
    cout<<"\n"<<endl;

    cout<<"dicha área tiene como objetivo muy concreto que es cumplir con las reglas impuestas por el "<<endl;
    cout<<"servicio de administración tributaria (SAT), el IMSS, el infonavit"<<endl;
    cout<<"\n"<<endl;

    cout<<"Área de administración \n"<<endl;

    cout<<"Esta área es la pendiente del tesoro de la empresa, por lo que también se le conoce como tesorería. En esta área \n"<<endl;
    cout<<"se realizarán todas las actividades que puedan entrar y salir del flujo de dinero. Ojo el almacén, también es un tesoro, \n"<<endl;
    cout<<"así también hay que contemplar esto, \"el objetivo de esta es llevar a cabo todas las tareas y procesos que se tienen que hacer,\" \n"<<endl;
    cout<<"\"con toda la documentación correspondiente para que entre y salga un tesoro, un ejemplo de esto seria una factura de un proveedor,\n"<<endl;
    cout<<"pagarla y registrarla en un software especializado o bien que el software haga los cálculos correspondientes como por ejemplo el calculo \n"<<endl;
    cout<<"del pago de salarios de los empleados.\n"<<endl;

    break;

    case 1:
    cout<<"******************************** \n"<<endl;
    cout<<"*   MODELO DE COSTO LINEAL     * \n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"\n"<<endl;

    cout<<"¿Que es el modelo de costo lineal?"<<endl;
    cout<<"para simplificarlo, constituye el costo de produccion y de los ingresos totales que se generan en la empresa"<<endl;
    cout<<"Los costos totales se dividen en costos fijos y costos variables (recordando que se dividen en produccion)"<<endl;
    cout<<"\n"<<endl;

    cout<<"Funcion de ingresos (oferta y demanda)."<<endl;
    cout<<"Los ingresos se definen como una cantidad de dinero que percibe una empresa por la venta de sus productos o prestacion"<<endl;
    cout<<"de sus servicios el modelo matematico para esta operacion relizada es la funcion de ingresos"<<endl;
    cout<<"\n"<<endl;
    cout<<"Explicacion de la entrada de datos en el modelo de costo lineal: \n"<<endl;
    cout<<"\n"<<endl;

    cout<<"COSTO VARIABLE"<<endl;
    cout<<"el costo variable es la cantidad de productos a fabricar o generar o bine el servicio que se dara a cierto cliente, empresa o usuario"<<endl;
    cout<<"aun a este costo no se le \"asigna\"  el preio final, si no es mas bien el costo de hacer cierto producto o bien entregarlo"<<endl;
    cout<<"en la entrada de tu programa amschel digitaras la cantidad de productos de usted ofrecera"<<endl;
    cout<<"\n"<<endl;
    cout<<"CANTIDAD DE PRODUCTOS QUE SE PRODUCIRAN"<<endl;
    cout<<"cuantos productos se van a producir en su negocio o entrega de bienes que usted ofrece"<<endl;
    cout<<"\n"<<endl;
    cout<<"COSTO FINAL DE SU PRODUCTO"<<endl;
    cout<<"Aqui digitara el costo que usted dara su producto o servicio, el vbalor agregado por usted a su producto para recibir una ganancia neta"<<endl;
    cout<<"\n"<<endl;

    cout<<"al final obtendra la cantidad de produccion total de su producto con el monto total de ganacia incluido en su operacion de calculo MODELO DE COSTO LINEAL \n"<<endl;
    cout<<"\n"<<endl;
    break;

    case 2:
    cout<<"******************************** \n"<<endl;
    cout<<"*     INGRESOS OBTENIDOS       * \n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"\n"<<endl;

    cout<<"Los ingresos se definen como la  \"la cantidad de dinero que percibe una empresa o negocio por la venta de sus productos\" "<<endl;
    cout<<" o \"prestacion de servicios; a esto se maneja como funcion de ingresos.\" "<<endl;
    cout<<"\n"<<endl;

    cout<<"Los ingresos obtenidos se obtienen con los siguientes datos \n"<<endl;

    cout<<"ENTRADA PRECIO DE LOS PRODUCTOS: \n"<<endl;

    cout<<"El precio es el valor monetario que se le asigna a un producto o servicio al momento de ofrecerlo a los consumidores y"<<endl;
    cout<<"por tanto, el valor monetario que los consumidores deben pagar a cambio de obtener dicho producto o servicio."<<endl;
    cout<<"\n"<<endl;

    cout<<"ENTRADA CANTIDAD DE PRODUTOS A OFRECER \n"<<endl;
    cout<<"cuantos productos se van a producir en su negocio o entrega de bienes que usted ofrece, fabricar o obtener"<<endl;
    cout<<"\n"<<endl;

    cout<<"SALIDA INGRESO QUE OBTENDRAS DE TU PRODUCTO \n"<<endl;
    cout<<"el ingreso total que se calcula por todos tus productos ofertados u obtenidos, la ganancia total de lo percibido \n"<<endl;
    cout<<"\n"<<endl;
    break;

    case 3:
    cout<<"\n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"*          INTERES TOTAL       * \n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"\n"<<endl;

    cout<<"El interes tottal es la cantidad que se paga o se cobra (segun sea el caso) por el uso del dinero, cuando se calcula el interes"<<endl;
    cout<<"se consideran tres factores de entrada para realizar el calculo del interes simple "<<endl;

    cout<<"ENTRADA TIEMPO: \n"<<endl;
    cout<<"Para efecto del calculo, el tiempo debe estar expresado en las mismas unidades que la tasa, un ejemplo claro es cuando si se tiene una"<<endl;
    cout<<"una tasa del 20% anual, el tiempo se expresa en años y en meses para un control de tiempo mas estricto, (tiempo en se dura el prestamo)"<<endl;
    cout<<"\n"<<endl;

    cout<<"ENTRADA CAPITAL TRANSFERIDO: \n"<<endl;
    cout<<"El capital es la cantidad inicial de dinero que se invierte o se presta; a veces llamado principal, valor actual o valor presente"<<endl;
    cout<<"varia en funcion del tiempo y del interes establecido"<<endl;


    cout<<"ENTRADA PORCENTAJE DE INTERES: \n"<<endl;
    cout<<"La tasa de interés es la cantidad de dinero que por lo regular representa un porcentaje del crédito o préstamo que se ha requerido y que el deudor"<<endl;
    cout<<"deberá pagar a quien le presta. En términos simples; es el precio del uso del dinero y por el cual se maneja en tanto porciento [%]"<<endl;
    cout<<"\n"<<endl;
    break;

    case 4:
    cout<<"\n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"*   MONTO TOTAL DE UN PAGARE   * \n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"\n"<<endl;

    cout<<"El pagare es un titulo de credito por medio del cual una persona o varias estan obligadas a pagar una cantidad determinada, dentro de un tiempo preciso"<<endl;
    cout<<"a otra persona, a la que llamaremos beneficiario"<<endl;
    cout<<"Los pagares son documentos comerciales con los que tenemos contacto de forma muy frecuente; basicamente es el credito que se le otorga junto con in interes"<<endl;
    cout<<"que se eleva segun el tiempo transcurrido \n"<<endl;

    cout<<"ENTRADA DE TIEMPO \n"<<endl;
    cout<<"Para efecto del calculo, el tiempo debe estar expresado en las mismas unidades que la tasa, un ejemplo claro es cuando si se tiene una"<<endl;
    cout<<"una tasa del 30% anual, el tiempo se expresa en años y en meses para un control de tiempo mas estricto, (tiempo en se dura el prestamo)"<<endl;
    cout<<"\n"<<endl;

    cout<<"ENTRADA PORCENTAJE DE INTERES \n"<<endl;
    cout<<"Es un monto de dinero que normalmente corresponde a un porcentaje de la operación de dinero que se esté realizando."<<endl;
    cout<<"Si se trata de un crédito?, la tasa de interés es el monto que el deudor deberá pagar a quien le presta, por el uso de ese dinero."<<endl;
    cout<<"Usted tendra que realizar la entrada de datos en porcentaje ejemplo --> 14[%] de intereses como lo estipule su deuda/pago \n"<<endl;
    break;

    case 5:
    cout<<"\n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"*         VALOR ACTUAL         * \n"<<endl;
    cout<<"******************************** \n"<<endl;
    cout<<"\n"<<endl;
    cout<<"Al valor de mercancia o valor del prestamo, antes de agregar los intereses, se le llama valor actual de deuda, ya incluye el el valor de la mercancia"<<endl;
    cout<<"o prestamo, antes de agregar los intereses, tambien se le conoce como valor de deuda o valor actual de la operacion"<<endl;
    cout<<"\n"<<endl;
    cout<<"ENTRADA VENCIMINETO DEL PAGARE (PRODUCTO O SERVICIO)\n"<<endl;
    cout<<"Es el tiempo establecido si el pagare fue acordado en un plazo de meses o dias, para efecto practico usted escogera segun sus intereses si su plazo es de meses o en dias"<<endl;
    cout<<"si su contrato se estipula en meses o en dias y cuando venece su contrato \n"<<endl;

    cout<<"ENTRADA CAPITAL APORTADO"<<endl;
    cout<<"Es el dinero que se ha recibido/cobrado de un pagare (producto o servicio) en un plazo estupilado de meses o dias, es lo abonado por usted (en caso de que sea deudor)"<<endl;
    cout<<"o el deudor que le debe \n"<<endl;

    cout<<"ENTRADA TASA DE INTERES \n"<<endl;
    cout<<"La tasa de interés es la cantidad de dinero que por lo regular representa un porcentaje del crédito o préstamo que se ha requerido y que el deudor"<<endl;
    cout<<"deberá pagar a quien le presta. En este caso es el porcentaje de interes acumulado y que este no se tomara en cuenta para calcular el valor actual del pagare"<<endl;
    cout<<"o producto o servicio que se ofrecio se dara un entrada en tanto porciento --> [%] \n"<<endl;

    cout<<"ENTRADA TIEMPO"<<endl;
    cout<<"Para efecto del calculo, el tiempo debe estar expresado en las mismas unidades que la tasa, un ejemplo claro es cuando si se tiene una"<<endl;
    cout<<"una tasa del 30% anual, el tiempo se expresa en años y en meses para un control de tiempo mas estricto, (tiempo en se dura el prestamo) \n"<<endl;
    cout<<"\n"<<endl;

    break;

    case 6:
    cout<<"\n"<<endl;
    cout<<"******************** \n"<<endl;
    cout<<"*      ENGANCHE    * \n"<<endl;
    cout<<"******************** \n"<<endl;
    cout<<"\n"<<endl;
    cout<<"Para comenzar, enganche se le llama a la cantidad que una persona da inicialmente al"<<endl;
    cout<<"comprar un producto, servicio o bien un inmueble a crédito. Este valor puede ser del 20% al 35% del valor total del inmueble y existe para asegurar la venta de dicho objeto"<<endl;
    cout<<"Si no existiera un enganche para la adquisición del crédito, el proceso sería mucho más inseguro para el vendedor y tú podrías perder la casa o el apartamento si al vendedor"<<endl;
    cout<<"le dieran una mejor oferta que la que tú hiciste. Por eso, es que se debe respetar, para que ambas partes estén seguras del negocio y asi mantener la compra/venta asegurada \n"<<endl;

    cout<<"ENTRADA PORCENTAJE DE ENGANCHE \n"<<endl;

    cout<<"Se trata de una suma de dinero inicial que debes de dar para así asegurar el contrato de compra-venta. Es muy común que este se maneje como algún porcentaje del"<<endl;
    cout<<"inmueble que vayas a adquirir. Aunque no existe algún documento en el que se determine la cantidad que se tiene que dar de enganche para contratar un"<<endl;
    cout<<"crédito etablecido \n"<<endl;

    cout<<"ENTRADA PORCENTAJE FALTANTE A PAGAR \n"<<endl;
    cout<<"Es el faltante que se debe pagar del pagare o producto establecido en el contrato de dicha compra"<<endl;

    cout<<endl;
    break;

    case 7:
    cout<<" ********************************************** \n"<<endl;
    cout<<" *  DESCUENTO REAL (O SIMPLEMENTE DESCUENTO)  * \n"<<endl;
    cout<<" *  calculo que se encuantra el valor actual  * \n"<<endl;
    cout<<" ********************************************** \n"<<endl;
    cout<<"\n"<<endl;
    cout<<"Las instituciones bancarias, negocios y empresas realizan un operacion mediante la cual un documento,"<<endl;
    cout<<"como los pagares o una \"letra\", con fecha"<<endl;
    cout<<"de vencimiento a futuro, es pagado por la institucion con el valor nominal del documento,"<<endl;
    cout<<"menos el descuento (puede que en tu negocio apliques algun tipo)"<<endl;
    cout<<"de promocion o descuento de tus productos o servicios "<<endl;
    cout<<"tecnicamente, el descuento es una operacion que resta el valor a pagar,"<<endl;
    cout<<"cuando se paga antes de la fecha de vencimiento \n"<<endl;

    cout<<"SALIDA DESCUENTO REAL \n"<<endl;
    cout<<"Es el descuento que se realizo a un producto, ya sea si realizo usted el descuento"<<endl;
    cout<<"(aplico), o aplicaron el descuento a su producto"<<endl;
    cout<<"\n"<<endl;
    break;

    case 8:
    cout<<" ********************************************** \n"<<endl;
    cout<<" *              DESCUENTO BANCARIO            * \n"<<endl;
    cout<<" ********************************************** \n"<<endl;
    //VERIFICAR ESTE CASE PORQUE SE REPITE EN EL VALOR ACTUAL
    cout<<"\n"<<endl;
    break;

    case 9:
    cout<<" ********************************************** \n"<<endl;
    cout<<" *             INFLACION FUTURA               * \n"<<endl;
    cout<<" ********************************************** \n"<<endl;
    cout<<"\n"<<endl;

    cout<<"hablar de la inflacion, la cual no es otra cosa que un tipo de interes; la inflacion es en realidad la tasa de interes con la cual el"<<endl;
    cout<<"dinero cambia su poder adquisitivo. Esto no quiere decir que a medida que transcurre el tiempo las cosas son mas caras; esto significa"<<endl;
    cout<<"que a medida que pasa el tiempo el dinero pierde poder adquisitivo"<<endl;

    //cout<<
    break;

    default:
    cout<<"entrada no reconocida"<<endl;
    break;
  }
}
 //aqui se desarrollara un sistema pequenio de ayuda al usuario por cada tema, pasar el sistema a amscheln y empezar con lo de ncurses
//empezar a documentar todo lo relacionado con amschel

void sistema_opciones(); //sistema implementado con un swich que controla lo que quiero calcular

int main(void){
system("color 09");
sistema_opciones();

system("pause");
}
void sistema_opciones(){

  MClineal ObjMClineal;
  Funcion_ingresos ObjFI;
  Interes Objinteres1;
  MontoTotal ObjMonto;
  Valor_actual ObjVal;
  DescuentoB ObjDesB;
  Inflacion ObjInfl;
  helpme Objhelp;

  int *Opciones = new int;
  int op;
  op = 1;
  while(op == 1){
  cout<<endl;
  cout<<"\t**************************************************************************\n"<<endl;
  cout<<"\t* Acontinuacion seleccione que es lo que quiere calcular:                *\n"<<endl;
  cout<<"\t**************************************************************************\n"<<endl;
  cout<<"\t* [1]--> Calcular modelo de costo lineal                                 *\n"<<endl;
  cout<<"\t* [2]--> Calcular Ingresos obtenidos                                     *\n"<<endl;
  cout<<"\t* [3]--> Calcular el interes total                                       *\n"<<endl;
  cout<<"\t* [4]--> Calcular el monto final de deuda/pago                           *\n"<<endl;
  cout<<"\t* [5]--> Calcular el valor original (sin interes)                        *\n"<<endl;
  cout<<"\t* [6]--> Calcular el descuento bancario                                  *\n"<<endl;
  cout<<"\t* [7]--> Calcular la Inflacion futura                                    *\n"<<endl;
  cout<<"\t* [8]--> Manual de usuario                                               *\n"<<endl;
  cout<<"\t**************************************************************************\n"<<endl;


  cout<<"Opcion$>"; //tal vez cambies estas opcion
  cin>>*Opciones;
  cout<<"\n"<<endl;

  switch (*Opciones) {
    case 1:
    cout<<"\n"<<endl;
    cout<<"******************************************************\n"<<endl;
    cout<<"*  HAZ ESCOGIDO CALCULAR EL MODELO DE COSTO LINEAL   *\n"<<endl;
    cout<<"******************************************************\n"<<endl;
    cout<<"\n"<<endl;
    ObjMClineal.Pedir_dmclineal();
    ObjMClineal.Operacion_mclineal();
    ObjMClineal.Mostrar_mclineal();
    cout<<endl;
    break;

    case 2:
    cout<<"\n"<<endl;
    cout<<"****************************************************** \n"<<endl;
    cout<<"*    HAZ ESCOGIDO EL CALCULO DE INGRESOS OBTENIDOS   * \n"<<endl;
    cout<<"****************************************************** \n"<<endl;
    cout<<"\n"<<endl;
    ObjFI.pedir_datosI();
    ObjFI.Calcular_ingresos();
    ObjFI.Mostrar_ingresos();
    cout<<endl;
    break;

    case 3:
    cout<<"\n"<<endl;
    cout<<"*********************************************** \n"<<endl;
    cout<<"*   HAZ ESCOGIDO CALCULAR EL INTERES SIMPLE   * \n"<<endl;
    cout<<"*********************************************** \n"<<endl;
    cout<<endl;
    Objinteres1.Calcular_interes();
    cout<<endl;
    break;

    case 4:
    cout<<"\n"<<endl;
    cout<<"******************************************************* \n"<<endl;
    cout<<"*  HAZ ESCOGIDO CALCULAR EL MONTO TOTAL DE UN PAGARE  * \n"<<endl;
    cout<<"******************************************************* \n"<<endl;
    cout<<"\n"<<endl;
    ObjMonto.MontoT();
    cout<<endl;
    break;

    case 5:
    cout<<"\n"<<endl;
    cout<<"**************************************************** \n"<<endl;
    cout<<"*  HAZ ESCOGIDO CALCULAR EL VALOR TOTAL DE INTERES * \n"<<endl;
    cout<<"**************************************************** \n"<<endl;
    cout<<"\n"<<endl;
    ObjVal.Calcular_valorI();
    cout<<endl;
    break;

    case 6:
    cout<<"\n"<<endl;
    cout<<"************************************************ \n"<<endl;
    cout<<"* HAZ ESCOGIDO CALCULAR EL DESCUENTO BANCARIO  * \n"<<endl;
    cout<<"************************************************ \n"<<endl;
    cout<<"\n"<<endl;
    ObjDesB.CalcularDescuento();
    cout<<endl;
    break;

    case 7:
    cout<<"\n"<<endl;
    cout<<"******************************************** \n"<<endl;
    cout<<"*   HAZ ESCOGIDO CALCULAR EL MONTO TOTAL   * \n"<<endl;
    cout<<"******************************************** \n"<<endl;
    cout<<"\n"<<endl;
    ObjInfl.MontoT();
    cout<<endl;
    break;

    case 8:
    cout<<"\n"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
    cout<<"+++++BIENVENIDO AL MANUAL DE USUARIO PARA AMSCHEL++++++++\n"<<endl;
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"<<endl;
    cout<<"\n"<<endl;
    Objhelp.mostrar_ayuda();
    cout<<"\n"<<endl;

    break;

    default:
    cout<<"NO SE RECONOCE LA ENTRADA ERROR! \n"<<endl;
    break;
  }

  cout<<"si quieres volver al menu principal, digita 1: ";
  cin>>op;
  system("cls");
 }
}
