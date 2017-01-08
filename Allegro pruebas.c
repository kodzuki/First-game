
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_image.h>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#define FPS 5
#define lengt 1280
#define width 720
using namespace std;
void inicio(ALLEGRO_DISPLAY **display);
inline void validar(const char* progreso, int *a, int *timing);
inline void draw(char v [][4],ALLEGRO_BITMAP **mapa, ALLEGRO_BITMAP **fondo);
void menu(ALLEGRO_DISPLAY **display);
void player(ALLEGRO_DISPLAY **display,ALLEGRO_BITMAP **arriba);
void splayer(ALLEGRO_DISPLAY **display,ALLEGRO_BITMAP **arriba);
void cplayer(ALLEGRO_DISPLAY **display,ALLEGRO_BITMAP **arriba);
void puntuaciones(ALLEGRO_DISPLAY **display, int *puntos, const char* playa);
int main(){
    ofstream punt;
string puntu;
puntu = "Nueva partida \n\n ";
punt.open("puntuaciones.txt",ios::app);
punt << puntu;
punt.close();

al_set_new_display_flags(ALLEGRO_FULLSCREEN);


if(!al_init()){

    al_show_native_message_box( NULL,NULL, NULL, "No ze pue iniciá",NULL,NULL);
    return -1;
}
ALLEGRO_DISPLAY *display;

display = al_create_display(1280, 720);

al_set_window_position(display,200,100);
al_set_window_title(display, "Juego");


if(!display){


    al_show_native_message_box(display,"Hola", "Opciones", "Menu",NULL,NULL);
}

menu(&display);

al_destroy_display(display);



        return 0;

}

void inicio(ALLEGRO_DISPLAY **display, const char* jugad){

int i,j,p,a,b,q,r,t,x,y,h,g,c,o,n,timing;
int pause;
pause = 0;
int punt;
timing = 10;
punt = 0;
o = 3;
n = 0;

int inicio;
inicio = 0;
    char u;
    const char* progreso;
    for (i = 0; i < 10; i++){
        progreso[i] == ' ';
    }
    int aux;

string string;

    char d;
    char v[4][4];

al_init_font_addon();
al_init_ttf_addon();
al_init_primitives_addon();
ALLEGRO_BITMAP *mapa;
ALLEGRO_BITMAP *fondo;
ALLEGRO_BITMAP *crono;
ALLEGRO_BITMAP *lose;
lose = al_load_bitmap("pierde.jpg");
crono = al_load_bitmap("crono.png");
fondo= al_load_bitmap("fondo.png");
mapa = al_load_bitmap("google.png");
ALLEGRO_FONT *font = al_load_font("comici.ttf",40,NULL);
ALLEGRO_FONT *fonto = al_load_font("comici.ttf",30,NULL);
ALLEGRO_FONT *fant = al_load_font("comici.ttf",20,NULL);
srand(time(NULL));
for(j = 0; j < 4; j++){
for( p = 0; p < 4; p++){
a=	rand()%25;
b =rand()%100;
if(a == 13 && b < 10 ){
	a = '/';
}
else{

a = a + 65;

}
d = a;

v[j][p] = d;

}
}


draw(v,&mapa,&fondo);


ALLEGRO_TIMER *timer = al_create_timer(1.0/FPS);
ALLEGRO_EVENT_QUEUE *allegro_event = al_create_event_queue();

al_register_event_source(allegro_event, al_get_keyboard_event_source());
al_register_event_source(allegro_event, al_get_timer_event_source(timer));
bool done = false;
al_start_timer(timer);
while(!done){



t++;

if(pause == 0){
    ALLEGRO_EVENT events;
    al_wait_for_event(allegro_event, &events);

    if(events.type == ALLEGRO_EVENT_KEY_DOWN){
        if(events.keyboard.keycode == ALLEGRO_KEY_UP || events.keyboard.keycode == ALLEGRO_KEY_ESCAPE){

                pause = 1;
        }
        else if((events.keyboard.keycode == ALLEGRO_KEY_DELETE || events.keyboard.keycode == ALLEGRO_KEY_BACKSPACE) && string.length()> 0){

cout << "string - 1"<< endl;
              string.erase( string.end()-1 );
              progreso = string.c_str();

        }
    }
        if(events.type == ALLEGRO_EVENT_KEY_CHAR){
      c = events.keyboard.unichar;

      if(c >= 97 && c <= 122){
        c = c-32;
      }

           	if((c >= 65 && c <= 90) || c == 47){

cout << "Caracter pulsado"<<endl;
o = 0;
inicio = 1;

	for(j = 0; j < 4; j++){

		for( i = 0; i < 4; i++){
				if(v[j][i] == c){
					o = 1;
					cout << "Caracter Valido"<< endl;
				}

		}
	}



if(o == 1 && string.length() < 10) {

         u = c;
string.push_back(u);
progreso = string.c_str();
cout << "string temporal = " << string << endl;
        }
           	}
	else if(c == 13){

cout << "Enter pulsado" << endl;
	    a = string.length();
    char progres[a];

    for(i = 0; i < a; i++){
        progres[i] = (string[i] + 32);
    }

            string.erase(string.begin(),string.end());
		validar(progres,&punt,&timing);

	}

           }
    if(events.type == ALLEGRO_EVENT_TIMER){

            if((al_get_timer_count(timer)%FPS) == 0){
                timing--;

            }
if(o == 0){
    n++;
if(n==1){
    timing--;
}
    if(n == 4){
        o = 3;
        n = 0;
    }
}

       do{
        a =	rand()%25;
        b = rand()%100;
    if(a == 13 && b < 10 ){
	 a = '/';
    }
	 else{
             a = a + 65;
}
if((t % 4) == 0){
    g = (rand()%4) + 1;
    switch(g){
    case 1: a = 65;break;
    case 2: a = 69;break;
    case 3: a = 73;break;
    case 4: a = 79;break;
    case 5: a = 85;break;
    }

}
       }while(a == h && ((t % 5) != 0));
       h = a;
       do{
         q = (rand()%4) ;
        r = (rand()%4) ;
        if (t%2 == 0){
            aux = q;
            q = r;
            r = aux;
        }

       }while( q == x && r == y);

        x = q;
        y = r;

       for(j = 0; j < 4; j++){
     for( p = 0; p < 4; p++){


      if(p == q && j == r){
     v[j][p] = a;

}
}
}
}
}

else if (pause == 1){

        ALLEGRO_EVENT eventual;
    al_wait_for_event(allegro_event, &eventual);

    if(eventual.type == ALLEGRO_EVENT_KEY_DOWN){
            if (eventual.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
                pause = 0;

            }

        else if(eventual.keyboard.keycode == ALLEGRO_KEY_ENTER){

done = true;
menu(display);

            al_destroy_bitmap(fondo);
            al_destroy_bitmap(mapa);
            al_destroy_bitmap(crono);
            al_destroy_bitmap(lose);
            al_destroy_font(font);
            al_destroy_font(font);
            al_destroy_font(fant);


        }

    }
al_flush_event_queue(allegro_event);

}

          draw(v,&mapa,&fondo);

            al_draw_rectangle(1000,100,1200,150,al_map_rgb(0,0,0),130);
            al_draw_textf(font,al_map_rgb(255,255,255), 1100,120,ALLEGRO_ALIGN_CENTER,"Score: %i",punt);
            al_draw_filled_rectangle(680-(61*timing),65,750,20,al_map_rgb(0,0,0));
            al_draw_textf(font,al_map_rgb(255,255,255),(710-(timing*61)),15,ALLEGRO_ALIGN_CENTER,"%i",timing);
            al_draw_text(font, al_map_rgb(255,255,255), 1100,55,ALLEGRO_ALIGN_CENTER,jugad);
            al_draw_bitmap(crono,770,12,0);
            if (inicio == 1){

            al_draw_text(font, al_map_rgb(0,0,0), 1050,600,ALLEGRO_ALIGN_CENTER,progreso);

            }

if( n != 0){
    al_draw_text(fonto,al_map_rgb(0,0,0),1050,500,ALLEGRO_ALIGN_CENTER,"Introduzca una letra correcta");
    al_draw_text(font,al_map_rgb(255,255,255),(760-(timing*66*0.9)),15,ALLEGRO_ALIGN_CENTER,"-1");
}
if(pause == 1){

 al_draw_rectangle(0,0,1280,720,al_map_rgb(0,0,0),60);
    al_draw_filled_rectangle(400,230,880,530,al_map_rgb(0,0,0));
    al_draw_text(font, al_map_rgb(255,255,255), 650,270,ALLEGRO_ALIGN_CENTER,"PAUSE");
    al_draw_text(fant, al_map_rgb(255,255,255), 520,450,ALLEGRO_ALIGN_CENTER,"ENTER : EXIT");
    al_draw_text(fant, al_map_rgb(255,255,255), 760,450,ALLEGRO_ALIGN_CENTER,"ESC : CONTINUE");


}
if(timing < 0){
    al_draw_bitmap(lose,1,0,0);
    al_draw_text(font, al_map_rgb(0,0,0), width/2,470,ALLEGRO_ALIGN_CENTER,"Irá mejor la próxima vez...");
al_flip_display();
    Sleep (3000);
    char playa[strlen(jugad)];
    for (i = 0; i < strlen(jugad); i++){
        playa[i] = jugad[i];
    }
    al_clear_to_color(al_map_rgb(0,0,0));
    puntuaciones(display,&punt,playa);

}

al_flip_display();
al_clear_to_color(al_map_rgb(0,0,0));

}

}

inline void draw(char v[][4],ALLEGRO_BITMAP **mapa,ALLEGRO_BITMAP **fondo){

al_init_primitives_addon();
al_init_font_addon();
al_init_ttf_addon();
al_init_image_addon();
ALLEGRO_FONT *font = al_load_font("comici.ttf",40,NULL);
al_draw_bitmap(*fondo,0,0,0);
al_draw_bitmap(*mapa,100,100,0);
int j,e,i,x,y;


string val;
const char* p;
srand (time(NULL));

int k;
k = 0;


	for(j = 0; j < 4; j++){

for( e = 0; e < 4; e++){

val[0] = v[j][e];
string sym(1,val[0]);
p = sym.c_str();
x = ((175*j)+180);
y = ((127*e)+135);
if(((e % 2) == 0 && (j % 2) == 0) || (e == 1 && j == 3) || (e == 3 && j == 1) || (e == 1 && j == 1) || (e == 3 && j == 3)){
    al_draw_text(font, al_map_rgb(255,255,255),x,y,ALLEGRO_ALIGN_CENTER,p);
}
else{

al_draw_text(font, al_map_rgb(0,0,0),x,y,ALLEGRO_ALIGN_CENTER,p);
}
}
	}

}
inline void validar(char const *progreso, int *a, int *timing){
	string prueba;
	int i,k;
	k = 0;
al_init_font_addon();
al_init_ttf_addon();
al_init_primitives_addon();
ALLEGRO_FONT *font = al_load_font("comici.ttf",40,NULL);
al_init_image_addon();
ALLEGRO_BITMAP *imagen;
ALLEGRO_BITMAP *image;
 imagen = al_load_bitmap("imagen.png");
image = al_load_bitmap("imag.png");
		ifstream dicc;

	dicc.open("diccionario.txt", ios::app);
cout << "comprobando diccionario" << endl;
	while(!dicc.eof() && k == 0){
		i = 0;

		getline(dicc,prueba);

		if (prueba.length() > 2){

		do{
			if(prueba[i] != '\n' && prueba[i] != ' '){
				if(prueba[i] == 'á' ){
					prueba[i] = 'a';
				}
					else if(prueba[i] == 'í' ){
					prueba[i] = 'i';
				}
				else	if(prueba[i] == 'ú' ){
					prueba[i] = 'u';
				}
				else	if(prueba[i] == 'é' ){
					prueba[i] = 'e';
				}
					if(prueba[i] == 'ó' ){
					prueba[i] = 'o';
				}

				if(prueba[i] ==  progreso[i]){
					k = 1;
				}
				else{
					k = 0;
				}

			}
			i++;

		}while(i < prueba.length() && k == 1);

		}
		}


  if(k == 1){
*a = *a +(strlen(progreso)*10);
al_draw_text(font,al_map_rgb(255,255,255),0,0,ALLEGRO_ALIGN_CENTER,"¡¡Bien!!");
al_draw_bitmap(imagen,150,150,0);
cout << "imagen load corazon"<< endl;
cout << "Puntuación = " << *a<< endl;
cout << "Palabra valida = 1 : " <<progreso;
*timing = *timing + strlen(progreso);
if(*timing > 10){
    *timing = 10;
}
  }
  else{

        al_draw_text(font,al_map_rgb(255,255,255),0,0,ALLEGRO_ALIGN_CENTER,"¡¡Maaal!!");
al_draw_bitmap(image,150,150,0);
cout << "imagen load cruz"<< endl;

  }
al_flip_display();
al_rest (0.5);
al_destroy_bitmap(imagen);
al_destroy_bitmap(image);


}
void menu(ALLEGRO_DISPLAY **display){

int a,i,l;
l = 0;
i = 0;
a = 0;
al_init_font_addon();
al_init_ttf_addon();
al_init_primitives_addon();
al_init_image_addon();
ALLEGRO_FONT *font = al_load_font("comici.ttf",40,NULL);
ALLEGRO_FONT *fonto = al_load_font("comici.ttf",27,NULL);
ALLEGRO_BITMAP *arriba;
arriba = al_load_bitmap("flecha.png");
al_install_keyboard();
ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

al_register_event_source(event_queue, al_get_keyboard_event_source());

bool done = false;
while(!done){


    ALLEGRO_EVENT eventos;
    al_wait_for_event(event_queue, &eventos);
if(eventos.type == ALLEGRO_EVENT_KEY_DOWN){
    switch(eventos.keyboard.keycode){

    case ALLEGRO_KEY_UP:{
        if(a != 0){
            a--;
        }

    };break;
    case ALLEGRO_KEY_DOWN:{
        if(a != 2){
            a++;
        }

    }break;
    case ALLEGRO_KEY_ENTER:{
    if((a) == 0){
player(display,&arriba);

        cout << "Play seleccionado"<< endl;
    }
    else if(a == 1){

         l = 1;

    }
    else if(a == 2){
cout << "CERRANDO PROGRAMA" << endl;
al_destroy_display(*display);
exit(0);
    }
    }


}
}
if(l == 1){
    ifstream puntuacion;
         string jugapunt;
         puntuacion.open("Jugadores.txt");

         while(!puntuacion.eof()){
                i++;
            getline(puntuacion,jugapunt);
            al_draw_text(fonto,al_map_rgb(255,255,255),690,50+(50*i),ALLEGRO_ALIGN_CENTER,jugapunt.c_str());
             al_draw_text(fonto,al_map_rgb(255,255,255),690,50,ALLEGRO_ALIGN_CENTER,"Jugador");
              al_draw_text(fonto,al_map_rgb(255,255,255),390,50,ALLEGRO_ALIGN_CENTER,"Score");
            al_flip_display();
         }
puntuacion.close();
}
else{
if(a == 0){
al_draw_text(font,al_map_rgb(255,255,255),690,150,ALLEGRO_ALIGN_CENTER,"Play");
al_draw_text(font,al_map_rgb(255,255,255),690,300,ALLEGRO_ALIGN_CENTER,"Scores");
al_draw_text(font,al_map_rgb(255,255,255),690,450,ALLEGRO_ALIGN_CENTER,"Quit");
 al_draw_line(600,220,780,220,al_map_rgb(255,255,255),3.0);
}
else if(a == 1){
al_draw_text(font,al_map_rgb(255,255,255),690,150,ALLEGRO_ALIGN_CENTER,"Play");
al_draw_text(font,al_map_rgb(255,255,255),690,300,ALLEGRO_ALIGN_CENTER,"Scores");
al_draw_text(font,al_map_rgb(255,255,255),690,450,ALLEGRO_ALIGN_CENTER,"Quit");
 al_draw_line(600,370,780,370,al_map_rgb(255,255,255),3.0);
}
else if(a == 2){
al_draw_text(font,al_map_rgb(255,255,255),690,150,ALLEGRO_ALIGN_CENTER,"Play");
al_draw_text(font,al_map_rgb(255,255,255),690,300,ALLEGRO_ALIGN_CENTER,"Scores");
al_draw_text(font,al_map_rgb(255,255,255),690,450,ALLEGRO_ALIGN_CENTER,"Quit");
 al_draw_line(600,520,780,520,al_map_rgb(255,255,255),3.0);
}
al_draw_text(fonto,al_map_rgb(255,255,255),200,450,ALLEGRO_ALIGN_CENTER,"Up");
al_draw_text(fonto,al_map_rgb(255,255,255),220,520,ALLEGRO_ALIGN_RIGHT,"Down");
al_draw_text(fonto,al_map_rgb(255,255,255),200,380,ALLEGRO_ALIGN_CENTER,"Enter = Select");
al_draw_bitmap(arriba,220,445,0);
al_draw_bitmap(arriba,220,525,2);
al_flip_display();

al_clear_to_color(al_map_rgb(0,0,0));


}
}

al_destroy_font(font);
al_destroy_font(fonto);
al_destroy_bitmap(arriba);

}
void player(ALLEGRO_DISPLAY **display,ALLEGRO_BITMAP **arriba){
int a;

a = 0;
al_init_font_addon();
al_init_ttf_addon();
al_init_primitives_addon();
ALLEGRO_FONT *font = al_load_font("comici.ttf",40,NULL);
ALLEGRO_FONT *fonto = al_load_font("comici.ttf",27,NULL);
al_install_keyboard();
ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

al_register_event_source(event_queue, al_get_keyboard_event_source());

bool done = false;
while(!done){

    ALLEGRO_EVENT eventos;
    al_wait_for_event(event_queue, &eventos);
if(eventos.type == ALLEGRO_EVENT_KEY_DOWN){
    switch(eventos.keyboard.keycode){

    case ALLEGRO_KEY_UP:{
        if(a != 0){
            a--;
        }

    };break;
    case ALLEGRO_KEY_DOWN:{
        if(a != 2){
            a++;
        }

    }break;
    case ALLEGRO_KEY_ENTER:{
    if((a) == 0){
splayer(display,arriba);

        cout << "Seleccionar player"<< endl;
    }
    else if(a == 1){
            cout << "Crear player" << endl;
cplayer(display,arriba);

    }
    else if(a == 2){
cout << "atras" << endl;
menu(display);
    }
    }


}
}

if(a == 0){
al_draw_text(font,al_map_rgb(255,255,255),690,150,ALLEGRO_ALIGN_CENTER,"Select player");
al_draw_text(font,al_map_rgb(255,255,255),690,300,ALLEGRO_ALIGN_CENTER,"New player");
al_draw_text(font,al_map_rgb(255,255,255),690,450,ALLEGRO_ALIGN_CENTER,"Back");
 al_draw_line(600,220,780,220,al_map_rgb(255,255,255),3.0);
}
else if(a == 1){
al_draw_text(font,al_map_rgb(255,255,255),690,150,ALLEGRO_ALIGN_CENTER,"Select player");
al_draw_text(font,al_map_rgb(255,255,255),690,300,ALLEGRO_ALIGN_CENTER,"New player");
al_draw_text(font,al_map_rgb(255,255,255),690,450,ALLEGRO_ALIGN_CENTER,"Back");
 al_draw_line(600,370,780,370,al_map_rgb(255,255,255),3.0);
}
else if(a == 2){
al_draw_text(font,al_map_rgb(255,255,255),690,150,ALLEGRO_ALIGN_CENTER,"Select player");
al_draw_text(font,al_map_rgb(255,255,255),690,300,ALLEGRO_ALIGN_CENTER,"New player");
al_draw_text(font,al_map_rgb(255,255,255),690,450,ALLEGRO_ALIGN_CENTER,"Back");
 al_draw_line(600,520,780,520,al_map_rgb(255,255,255),3.0);
}
al_draw_text(fonto,al_map_rgb(255,255,255),200,450,ALLEGRO_ALIGN_CENTER,"Up");
al_draw_text(fonto,al_map_rgb(255,255,255),220,520,ALLEGRO_ALIGN_RIGHT,"Down");
al_draw_text(fonto,al_map_rgb(255,255,255),200,380,ALLEGRO_ALIGN_CENTER,"Enter = Select");
al_draw_bitmap(*arriba,220,445,0);
al_draw_bitmap(*arriba,220,525,2);

al_flip_display();

al_clear_to_color(al_map_rgb(0,0,0));


}
al_destroy_font(font);
al_destroy_font(fonto);
al_destroy_bitmap(*arriba);

}
void splayer(ALLEGRO_DISPLAY **display,ALLEGRO_BITMAP **arriba){

string jugador;
ifstream jug;

int i,j,a,b;
b = 0;
a = 0;
j = 0;
i = 0;
al_init_font_addon();
al_init_ttf_addon();
al_init_primitives_addon();
al_init_image_addon();
al_install_keyboard();
ALLEGRO_FONT *font = al_load_font("comici.ttf",40,NULL);
ALLEGRO_FONT *fonto = al_load_font("comici.ttf",30,NULL);

ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

al_register_event_source(event_queue, al_get_keyboard_event_source());

bool done = false;
while(!done){


    ALLEGRO_EVENT eventos;
    al_wait_for_event(event_queue, &eventos);
if(eventos.type == ALLEGRO_EVENT_KEY_DOWN){
    switch(eventos.keyboard.keycode){

    case ALLEGRO_KEY_UP:{
        if(a != 0){
            a--;
        }

    };break;
    case ALLEGRO_KEY_DOWN:{
        if(a != i){
            a++;
        }

    }break;
    case ALLEGRO_KEY_ESCAPE:{
    player(display,arriba);
    }
    case ALLEGRO_KEY_ENTER:{


        jug.open("Jugadores.txt",ios::app);
   while(!jug.eof()){
        getline(jug,jugador);
    if(j == a){
char jug[jugador.length()];
for (i=0; i < jugador.length(); i++){

    jug[i] = jugador[i];
}
        ofstream punt;
   punt.open("puntuaciones.txt", ios::app);
      punt << jugador;
      punt.close();

        inicio(display,jug);

    }
    j++;
   }
   jug.close();
    }
    }


}
i = 0;
jug.open("Jugadores.txt",ios::out);
cout <<"Listando jugadores" << endl;
while(!jug.eof()){
    getline(jug,jugador);
    i++;
    b = jugador.find(" ");
    jugador = jugador.substr(b);
    al_draw_text(fonto,al_map_rgb(255,255,255),690,50*i,ALLEGRO_ALIGN_CENTER,jugador.c_str());
}
jug.close();
al_draw_line(600,50+((a+1)*50),780,50+((a+1)*50),al_map_rgb(255,255,255),3.0);
al_draw_text(fonto,al_map_rgb(255,255,255),200,450,ALLEGRO_ALIGN_CENTER,"Up");
al_draw_text(fonto,al_map_rgb(255,255,255),220,520,ALLEGRO_ALIGN_RIGHT,"Down");
al_draw_text(fonto,al_map_rgb(255,255,255),200,380,ALLEGRO_ALIGN_CENTER,"Enter = Select");
al_draw_bitmap(*arriba,220,445,0);
al_draw_bitmap(*arriba,220,525,2);
al_flip_display();

al_clear_to_color(al_map_rgb(0,0,0));


}

al_destroy_font(font);
al_destroy_font(fonto);
al_destroy_bitmap(*arriba);

}
void cplayer(ALLEGRO_DISPLAY **display,ALLEGRO_BITMAP **arriba){
 string nombre;

 int i,j;

 j = 0;
al_init_font_addon();
al_init_ttf_addon();
al_install_keyboard();
ALLEGRO_FONT *font = al_load_font("comici.ttf",40,NULL);


ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

al_register_event_source(event_queue, al_get_keyboard_event_source());

bool done = false;
while(!done){

    ALLEGRO_EVENT eventos;
    al_wait_for_event(event_queue, &eventos);
if(eventos.type == ALLEGRO_EVENT_KEY_DOWN){
if(eventos.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
    player(display,arriba);
}
else if((eventos.keyboard.keycode == ALLEGRO_KEY_BACKSPACE || eventos.keyboard.keycode == ALLEGRO_KEY_DELETE) && (nombre.length() > 0)){

            nombre.erase( nombre.end()-1 );


}


}
else if(eventos.type == ALLEGRO_EVENT_KEY_CHAR ){
        if(eventos.keyboard.unichar != 13 && eventos.keyboard.unichar != 8 && eventos.keyboard.unichar != 127 && nombre.length() < 10){

    nombre.push_back(eventos.keyboard.unichar);

        }
        else if (eventos.keyboard.unichar == 13){


    if(j != 0){
            cout << nombre << " Creado";
        ofstream jugadores;
        jugadores.open("Jugadores.txt",ios::app);
        jugadores << nombre << "\n";
jugadores.close();
player(display,arriba);

    }
    j++;
        }
}

if(nombre.length() > 1 && j == 0){

    al_draw_text(font, al_map_rgb(255,255,255), 690,360,ALLEGRO_ALIGN_CENTER,nombre.c_str());
}
if( j != 0){


 al_draw_text(font, al_map_rgb(255,255,255), 690,360,ALLEGRO_ALIGN_CENTER,"Seguro?");
  al_draw_text(font, al_map_rgb(255,255,255), 690,250,ALLEGRO_ALIGN_CENTER,"Enter                          Esc");
}
al_flip_display();
al_clear_to_color(al_map_rgb(0,0,0));
}
al_destroy_font(font);
al_destroy_bitmap(*arriba);
}
void puntuaciones(ALLEGRO_DISPLAY **display, int *puntos, const char* playa){
    al_init_font_addon();
al_init_ttf_addon();

ALLEGRO_FONT *font = al_load_font("comici.ttf",60,NULL);


ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

al_register_event_source(event_queue, al_get_keyboard_event_source());

bool done = false;
while(!done){

    ALLEGRO_EVENT eventos;
    al_wait_for_event(event_queue, &eventos);
if(eventos.type == ALLEGRO_EVENT_KEY_CHAR){
if(eventos.keyboard.unichar == 115){
        ofstream puntu;
puntu.open("puntaciones.txt",ios::app);
puntu << "\n\n" << playa << " " << *puntos;
done = true;
}
else if(eventos.keyboard.unichar == 110){
   done = true;

}

}
al_draw_text(font,al_map_rgb(255,255,255),610,200,ALLEGRO_ALIGN_CENTER,"Desea guardar su resultado?");
al_draw_text(font,al_map_rgb(255,255,255),630,450,ALLEGRO_ALIGN_CENTER,"Si                         No");
al_flip_display();
al_clear_to_color(al_map_rgb(0,0,0));
}
al_destroy_font(font);
 menu(display);



}
