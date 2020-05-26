# Fighter Traighter
Documento de diseño de videojuego

## Moruyankii Fighter
Autores | Correo
| ------------ | :-------------: |
Amparo Rubio Bellón | amprubio@ucm.es
Anass Carreau Allagui | anasca01@ucm.es
Andrés de la Cuesta López | ancues02@ucm.es
Daniel Cortijo Gamboa| dcortijo@ucm.es
Eloy Moreno Cortijo | eloymore@ucm.es
Pedro Pablo Cubells Talavera | pablocub@ucm.es
Pablo Rodríguez Bobada García Muñoz | prodra02@ucm.es
Raúl Blas Ruiz | raulblas@ucm.es
Sebastián Sánchez-Hombría | sebsan01@ucm.es
Sergio Alberto Luis Cano|  serluis@ucm.es

[Sitio web](https://moruyankiifighter.github.io/FighterTraighter/)

### Versión 1.0 - 30 de enero de 2020
### Versión 1.1 - 22 de febrero de 2020

## Resumen

<table>
 <thead>
  <th colspan="2">Resumen</th>
 </thead>
 <tbody>
  <tr>
   <td>Géneros</td>
   <td>Acción, Lucha</td>
  </tr>
  <tr>
   <td>Modos</td>
   <td>Singleplayer, Multiplayer local</td>
  </tr>
  <tr>
   <td>Público objetivo</td>
   <td>13 años en adelante</td>
  </tr>
  <tr>
   <td>Plataformas</td>
   <td>PC</td>
  </tr>
  <tr>
   <td>Escenarios</td>
   <td>Un par de fondos con animación</td>
  </tr>
  <tr>
   <td>Cantidades</td>
   <td>3 personajes, 17 habilidades</td>
  </tr>
 </tbody>
</table>

Hitos| Fechas de hitos
------------ | -------------
1º hito | 24 de febrero de 2020
2º hito | 30 de marzo de 2020
3º hito | 27 de mayo de 2020
Fecha de propuesta del concepto | 29-01-20
Fechas de pre-producción | 01-02-2020
fin de diseño | 05-02-2020
Fechas de producción: 20-02-20
Fecha de lanzamiento: 27 de mayo de 2020



# Descripción
## Juego de acción 2D de lucha. 

El jugador puede elegir uno de los dos modos disponibles: jugar solo contra la I.A., o enfrentarse a otra persona en un 1vs1 local.

En ambos casos, se toma control de un personaje, que puede hacer uso de una serie de golpes básicos y habilidades al enfrentarse en un combate contra su rival. El combate lo ganará aquel que consiga reducir la vida de su oponente a 0 antes.

Una vez seleccionados los personajes, comienza una primera fase de entrenamiento, donde ambos tendrán un breve periodo de tiempo en el cual deberán golpear a un saco colocado entre ellos con sus ataques básicos de la manera indicada en pantalla. Al final de esta fase, el saco otorga habilidades equipables a cada uno de los personajes en función de su actuación relativo al objetivo especificado.

Una vez terminada esta fase, se pasa al combate: ambos jugadores se enfrentan haciendo uso de sus ataques básicos y habilidades. Cuando uno consigue reducir la vida del otro a 0, gana la ronda y consigue un punto. En el modo contra otra persona, después de cada ronda hay una nueva fase de entrenamiento en la que pueden conseguir ambos más habilidades. El jugador que logre salir victorioso a un mejor de 5 rondas se considerará el ganador.
### Tabla de contenidos
1. [Aspectos generales](#aspectosgenerales)
   1. [Relato breve y parcial de una partida típica](#relatobreve)
2. [Menús y modos de juego](#menusymodos)
   1. [Menús](#menus)
   2. [Interfaz](#interfaz)
   3. [Modos](#modos)
3. [Opciones](#opciones)
   1. [Configuración](#configuracion)
   2. [Controles](#control)
4. [Jugabilidad](#jugabilidad)
   1. [Mecánica](#mecanica)
   2. [Dinámica](#dinamica)
   3. [Estética](#estetica)
5. [Contenido](#contenido)
   1. [Escenarios](#escenarios)
   2. [Música](#musica)
   3. [Historia](#historia)
   4. [Personajes](#personajes)
   5. [Habilidades](#habilidades) 


# Aspectos generales <a name="aspectosgenerales"></a>
Fighter Traighter se inspira en los juegos de lucha arcade, pero moderniza el concepto añadiendo más variedad con técnicas/habilidades que se obtienen en una fase previa a cada ronda de combate (la fase de entrenamiento), donde los jugadores golpean un saco de distintas maneras para añadir habilidades nuevas a su arsenal.

Cada habilidad posee un cooldown específico en función de su poder. El jugador no podrá hacer uso de una habilidad hasta que concluya su tiempo de refresco.

El jugador experimentará combates rápidos y dinámicos donde la victoria durante las fases de entrenamiento le permitirán conseguir mayor control sobre sus opciones en la fase de combate que le prosiga.

En el modo arcade el jugador debe aguantar el máximo número de rondas posibles luchando contra la IA, con sus habilidades definidas desde la ronda inicial. 

Fighter Traighter es un juego destinado al jugador hardcore, debido al aspecto competitivo del 1vs1, que debe dominar en todos sus aspectos para obtener el rendimiento necesario para ganar.

El juego tiene lugar en un mundo post-apocalíptico en el que un desastre ha dejado la superficie de la tierra desertificada. Sin ninguna organización, la gente se ha reunido en campamentos de bandidos, y su mayor entretenimiento son las peleas de gladiadores, que son las que entablarán los jugadores.

Los 3 personajes del juego son algunos de estos gladiadores: un robot construido para combatir, un superviviente humano buscándose la vida y un zombi fruto de experimentos militares.

La estética refleja esta ambientación mediante el uso de paletas amarillentas y metálicas para el mundo, y música energética que acompaña el ánimo del momento.
 
### Vista general
En pantalla se observan los dos luchadores en el modo de 1v1, cada uno controlado por un jugador; sus habilidades y la vida restante de cada uno. Caja luchador dispone de dos habilidades para el combate, que consigue en una fase previa a este.
  
## Relato breve y parcial de una partida típica<a name="relatobreve"></a>

El jugador selecciona un modo: 2 jugadores o arcade. Después, selecciona su personaje (y si está jugando contra otra persona esta también escoge simultáneamente), y comienza la fase de entrenamiento.
En esta fase ambos jugadores golpean el saco durante 20 segundos, intentando cunmplir el objetivo descrito en pantalla. Tras esta fase el jugador que cumpla con el objetivo primero podrá escoger habilidades para la posterior fase de combate, mientras que el perdedor recibirá aleatorias. Una vez seleccionadas, pasan a la fase de combate.

En la fase de pelea ambos personajes combinan las habilidades obtenidas y sus movimientos básicos para atacarse, a la vez que intentan bloquear o esquivar los ataques del contrincante. Una vez uno haya reducido la salud de su oponente a 0, gana la ronda. Si ningún jugador ha ganado al mejor de 5 rondas, ambos jugadores entrarán en una nueva fase de entrenamiento en la que ganarán nuevas habilidades para la siguiente ronda. Quien  gane cinco rondas antes gana la partida. Una vez acabada la partida sale un menú final con el ganador de la partida y un botón que nos permite volver al menú principal.

Durante las fases de entrenamiento y combate los jugadores podrán acceder a un menú de pausa, a través del cual pueden ver  volver al menú de inicio, cambiar opciones y reanudar la partida.

# Menús y modos de juego<a name="menusymodos"></a>

## Menús<a name="menus"></a>

### Menú principal
El menú principal consta del título del juego, seguido de cuatro botones: hacer un combate 1v1(versus), entrar al  modo arcade, ir al menú de opciones y salir de juego.

### Menú de opciones

Al pulsar en el botón de opciones, se abre el menú correspondiente en el que se pueden cambiar configuraciones relacionadas con el juego, referentes a la resolución y tamaño de pantalla(graphics), audio(audio) y la posibilidad de cambiar los controles(controls).

### Menú de pausa

Durante el juego, si se pulsa el botón de pausa se detiene la acción del juego y se abre un menú con un botón de reanudar, uno de opciones y otro de salir que te devuelve al menú principal.

## Interfaz<a name="interfaz"></a>

En la fase de entrenamiento se muestra el objetivo de la ronda como un texto al principio, y se pone un temporizador de 4 segundos en la parte superior. Al terminar, se pasa a un menú en el que hay una columna para cada jugador (a excepción del modo arcade, en el que hay sólo una). En cada columna se muestran las habilidades obtenidas por el entrenamiento, y debajo de éstas la habilidad extra. Tras esto, cada columna se transforma en un inventario formado por los iconos de las habilidades, separadas en casillas. De este inventoario cada jugador puede escoger dos habilidades a equipar.

En la fase de combate se ven a los dos luchadores, su vida restante en la parte superior con una barra y dos iconos por cada personaje que representan las habilidades que llevan equipadas (y si están en cooldown) en la parte inferior.

## Modos de juego<a name="modos"></a>

### Arcade: 
El jugador se enfrenta a luchadores de IA hasta que pierda. En la fase de entrenamiento de éste, el jugador pega él sólo al saco, obteniendo dos habilidades de nivel medio-alto. En este modo solo hay una fase de entrenamiento al principio.

### 1v1: 
Dos personas entablan un duelo en una partida al mejor de 5 rondas, con el personaje que haya escogido cada uno, pudiendo seleccionar ambos el mismo. Entre cada combate y al inicio de la partida hay una fase de entrenamiento en la que cada jugador consigue habilidades que puede usar desde ese momento.

# Opciones<a name="opciones"></a>

## Configuración<a name="configuracion"></a>
En el menú de opciones el jugador puede cambiar el volumen del juego así como ver y modificar los controles básicos y de las habilidades del juego, movimiento, golpes y pausar. Además, en este menú se puede cambiar la resolución de la ventana de juego, y cambiar el modo de pantalla completa a ventana.

## Controles <a name="control"></a>
El juego se puede controlar con teclado y mando, cada uno con sus controles por defecto:

Con mando; el movimiento, saltar y agacharse es con  el joystick izquierdo o con el D-Pad. La B es un puñetazo normal, la A es un puñetazo fuerte, la X una patada normal, y la Y una patada fuerte. Las habilidades obtenidas están asignadas a los bumpers, según el jugador las coloque. El rompeguardia es con el trigger derecho y el bloqueo con el izquierdo. Si se pulsa el botón start, se abre el menú de pausa, desde el que se puede continuar la partida, abandonarla o ver los ataques del personaje del jugador que ha pausado (tan sólo si está en el modo arcade). En el modo entrenamiento, con el D-pad o joystick izquierdo se puede navegar el inventario y con la A se coge y suelta una habilidad.

Para un mando PS4 los botones equivalentes al mando Xbox realizan las mismas acciones.

Con teclado el movimiento se hace con las flechas de dirección (saltar hacia arriba y agacharse hacia abajo), los ataques básicos con W (puñetazo normal), Q (puñetazo fuerte), E (patada normal) y R (patada fuerte), las habilidades en 2 y 3 (simulando los triggers), el rompeguardia en T y bloqueo en Espacio. El menú de pausa se abre con el botón de escape. En el modo entrenamiento se navega el inventario con las flechas y se seleccionan habilidades con los botones asignados a habilidades (2 y 3).

# Jugabilidad<a name="jugabilidad"></a>

## Mecánica<a name="mecanica"></a>

El jugador puede moverse de izquierda a derecha, saltar y agacharse en función de si pulsa controles para desplazarse arriba o abajo, respectivamente. Puede usar ataques (puñetazos y patadas) mediante los botones principales, que harán daño a su oponente al conectar contra él. También puede usar las habilidades que consiga en el entrenamiento con los respectivos botones (triggers). Además, tiene a su disposición un rompeguardia y un bloqueo.

## Dinámica<a name="dinamica"></a>

Al principio de cada ronda hay una fase de entrenamiento en la que ambos jugadores golpean un saco de una manera que se les especifica. Al finalizar, el jugador que haya conseguido cumplir el objetivo propuesto elige una de dos habilidades que se le presentan, y el otro jugador consigue una habilidad aleatoria. Además, ambos jugadores reciben una habilidad extra añadida. Las habilidades tienen poder en función de la ronda. Cuantas más rondas lleven jugando, de mayor nivel serán.

Las habilidades se consiguen de forma acumulativa entre rondas: los jugadores tienen en todo momento disponibles las habilidades que han conseguido previamente. Se pueden equipar 2 habilidades simultáneamente. Una vez una habilidad ha sido usada durante el combate tiene un tiempo de cooldown, tiempo durante el cual no puede ser usada.

Los jugadores pueden bloquear los ataques de su oponente pulsando el botón respectivo, recibiendo solo una pequeña parte del daño. Sin embargo, si un jugador está bloqueando y el otro usa su rompeguardia, le rompe el bloqueo y deja abierto a ataques. Se crea una tríada entre los ataques, el bloqueo y el rompeguardia.

Si el jugador está saltando, los movimientos básicos ejecutados al pulsar los botones principales cambiarán a versiones aéreas. Si el jugador está agachado, su movimiento es más lento, y sus ataques son similares a los normales.
El jugador tiene una barra de puntos de vida, que al llegar a 0 otorgarán un punto al rival.

En el caso de la Inteligencia Artificial(IA), su funcionamiento se basa a intentar mantener una distacia "cómoda" con el jugador, lanzando habilidades cuando encuentra espacios libres y bloqueando los del rival. Para evitar el tiempo de reacción instantáneo, tiene un tiempo semialeatorio entre algunas de sus acciones, para no convertirse en un rival imbatible.

## Estética<a name="estetica"></a>

El juego está ambientado en un mundo post-apocalíptico, tras un evento que dejó el mundo desertificado. El método principal de entretenimiento es la pelea de gladiadores. El juego tiene lugar en un coliseo, y el jugador controla a uno de estos gladiadores.

Los habitantes de este mundo son diversos: desde humanos supervivientes a robots avanzados u oxidados, pasando por mutantes y animales extraños e incluso alienígenas.
Los colores y diseños reflejan el estado desértico y apocalíptico del mundo, con tonos amarillentos y oscuros en un estilo pixel art en referencia a los juegos de lucha de las maquinas arcade.

La música es electrónica, con un ritmo marcado semejante al de juegos arcade más antiguos.

# Contenido<a name="contenido"></a>

Un menú principal, con el icono del juego, con un escenario de lucha de fondo, una imagen de los gladiadores y cuatro botones: Arcade, 1vs1, Opciones y Salir.

El juego contiene 2 modos distintos, Arcade y 1vs1.

Existen 3 personajes distintos para elegir, cada uno con ataques básicos personalizados y estilos de juego distintos.

Hay un arsenal de 17 habilidades repartidas en 5 categorías distintas según su poder, que puede conseguir cualquier personaje.

## Escenarios<a name="escenarios"></a>
Durante la fase de entrenamiento los jugadores se encuentran en una sala con un saco entre ellos, denominada la sala de entrenamiento.

Cuando pasan a la fase de combate, los jugadores son trasladados a una nueva zona: el coliseo. En ella se puede observar
un campo de batalla para los combatientes, y al fondo, subidas en gradas, localizamos diferentes criaturas de este mundo animando a los luchadores.

En el modo arcade el fondo se vuelve boscoso y oscuro, aunque sigue habiendo espectadores.


## Música y sonido<a name="musica"></a>
Hay un total de 3 canciones que se repiten en bucle dentro de sus zonas de efecto, es decir, una para la pantalla de menú y selección de opciones, otra para la pantalla de selección de personajes, el modo entrenamiento y el combate, y otra más diferentes para el modo arcade.
Las habilidades y golpes básicos de los gladiadores tienen sonidos personalizados.
Además hay sonido en los botones de los distintos menús.

## Historia<a name="historia"></a>
Después de un accidente apocalíptico, la mayoría del mundo está desierta y entre los supervivientes la actividad más atractiva y popular es la pelea de gladiadores, en la que dos contrincantes dispuestos a ser el mejor luchan hasta que uno se proclame vencedor. Sin embargo, siempre hay unos favoritos: los más fuertes, ágiles o perspicaces. Son estos capaces de llenar los estadios hasta arriba: Mk WH00P el robot, Mockingbird el humano y el Sujeto F10R.

* Mk WH00P es un robot creado a partir de maquinaria destruida encontrada mientras se construía un coliseo. Fue programado para entretener a la gente a falta de luchadores de verdad, pero su popularidad y brutal eficacia aseguraron su puesto como un luchador más. 

* Mockingbird es un humano nacido como hijo de carroñeros y mercaderes. Su falta de medios le ha convertido en alguien sagaz e ingenioso, que siempre tiene una solución para salirse con la suya. Compite en combates para poder conseguir fama y gloria que le aseguren una vida menos dura. 

* El sujeto F10R es el resultado de los desesperados experimentos de un científico para descubrir la clave de la vida eterna, F10R era un humano que se ha fusionado por completo con una planta. Es extremadamente agresiva si se la provoca, y prefiere estar en lugares húmedos y solitarios.

## Personajes<a name="personajes"></a>
### Mk WH00P
Tiene un playstyle lento pero poderoso, con golpes contundentes y de alto empuje. Tiene una vida alta.
* Puñetazo normal: Se agacha ligeramente y tras un muy corto tiempo da un gancho hacia arriba. Daño y empujes medio, con tiempo de recuperación medio.
* Puñetazo fuerte: Junta ambas manos en un puño, golpeando en horizontal. Daño alto, poco alcance, poco empuje hacia delante y ligeramente hacia el suelo pero con recuperación media.
* Patada normal: Roza una de sus extremidades inferiores contra el suelo provocando una lluvia de chispas hacia el oponente. Tiene recuperación media, alcance medio-largo y daño medio.
* Patada fuerte: Pisa el suelo con una fuerza descomunal, alcanzando incluso a los que están un poco alejados de él. Daño bestial, pero lento y con poco rango; sin embargo, si alguien está en el suelo a cierta distancia, recibirá un poquito de daño y empuje cuando se realice el pisotón. Si impacta a alguien directamente, el empuje es algo mayor.
* (Aire) Puñetazo normal: Mk hace girar su torso, golpeando dos veces (una por cada brazo). Ambos golpes tienen daño medio-bajo y velocidad alta, teniendo el último golpe empuje medio-bajo. Dura más de lo habitual.
* (Aire) Puñetazo fuerte: Mk junta ambas manos en un puño y golpea hacia abajo. Velocidad baja, con empuje hacia abajo en diagonal enorme y daño alto. Alto período de recuperación.
* (Aire) Patada normal: Mk da dos patadas hacia abajo en diagonal, con empuje medio-bajo, daño medio-bajo y velocidad media-baja. La primera impactará cerca del torso o cuello del oponente y la segunda está dirigida a las piernas.
* (Aire) Patada fuerte: Mk transforma sus extremidades en ruedas de oruga y ataca delante suya, teniendo empuje y alcance medios, daño medio-alto y velocidad baja. Dura más de lo habitual (dropkick).
* Rompeguardia: Mk alza ambos brazos en ángulo recto, y tras un delay, los cruza, aplastando la guardia del oponente.



### Mockingbird
Sus ataques son rápidos pero de poco daño, promoviendo un playstyle de hacer combos mezclándolos. Tiene una vida baja.
* Puñetazo normal: Mockingbird apuñala con un puñal de su capa. Daño mínimo, empuje medio-bajo pero extremadamente rápido.
* Puñetazo fuerte: Con una tubería golpea delante como si fuera un bate. Daño moderado, empuje medio y velocidad media.
* Patada normal: De debajo de la capa saca una pistola oxidada y hecha a mano y dispara rápidamente un proyectil que hace poco daño, sin empuje y que tiene poco alcance.
* Patada fuerte: Un taconazo a los tobillos que lanza a su oponente hacia arriba en diagonal, con un daño medio y velocidad media-baja.
* (Aire) Puñetazo normal: Saca la mano de su manta y hace un karate chop de duración media, daño medio y empuje bajo.
* (Aire) Puñetazo fuerte: Da tres puñaladas rápidas en diagonal hacia abajo con mínimo empuje (excepto la última, con empuje bajo-medio), cada una con daño bajo.
* (Aire) Patada normal: Da una patada en horizontal con una cuchilla oculta. Daño bajo, pero rápida y con un ligero empuje hacia arriba.
* (Aire) Patada fuerte: Saca de debajo de su capa petardos que explotan al instante, haciendo daño medio con empuje fuerte hacia abajo en diagonal pero con bastante periodo de recuperación.
* Rompeguardia: Con una palanca engancha los brazos de su oponente y tira, abriendo sus defensas. Tiene un rango ligeramente mayor que el resto de rompeguardias.



### Sujeto F10R
Es capaz de atacar desde muy lejos, evitando que sus oponentes se acerquen, tiene el rol de zoner. Tiene una vida media-baja.
* Puño normal: F10R adelanta la cabeza y muerde rápidamente. Poco daño, empuje y alcance, pero gran velocidad.
* Puño fuerte: F10R extiende una zarza desde su brazo, haciendo daño y moderado a una rango considerable, con poco empuje y un periodo de recuperación medio.
* Patada normal: F10R extiende grandes espinas nudosas de sus piernas, mientras se arraiga ligeramente para estabilizarse, con daño y empuje buenos, pero con poco rango y velocidad media.
* Patada fuerte: F10R extiende raíces al suelo, que salen a cierta distancia suya haciendo daño y empuje vertical elevado, pero siendo lento y a una distancia fija.
* (Aire) Puño normal: F10R expulsa esporas a su alrededor, haciendo daño en un área amplia. Daño bajo, rango medio, alcance de 360 grados con empuje considerable y velocidad media-rápida.
* (Aire) Puño fuerte: F10R crea una raíz que va en diagonal hacia abajo y hacia delante suya. Mucho alcance y daño medio, pero empuje mínimo y bastante tiempo de recuperación.
* (Aire) Patada normal: F10R extiende espinas debajo suya, haciendo poco daño y empuje a quien impacte. Tiene velocidad y duración media, un alcance muy pobre, pero también empuja hacia arriba a F10R, dándole más tiempo para reposicionarse en el aire.
* (Aire) Patada fuerte: F10R ata raíces en forma de nudo debajo suya, haciendo mucho daño a los que impacte. Larga duración, alcance medio-alto, daño medio-alto y recuperación media.
* Rompeguardia: Hace crecer una flor en sus manos, esta explota en mucho polen, rompiendo la guardia del oponente, largo alcance.

 
# Habilidades<a name="habilidades"></a>
### NIVEL 5:

* Megaton Grip: Da un golpe de poco rango que deja estático al jugador mientras lo ejecuta y si impacta aturde al objetivo. Tras un tiempo aturdido en el cual recibe daño, se produce una explosión que daña y empuja al enemigo muy lejos.
Estéticamente, serían varias explosiones de fuego verdes, que al conectar mantienen agarrado al oponente y tras el daño continuo, hay una llamarada verde con rayos que empuja lejos y daña. 
Daño: 2 x golpes menores, 27 x golpe final /
Cooldown: 21 seg /
Rango: bajo

* Seismic Shock: Hace que tiemble el suelo, si ese primer golpe conecta con el oponente lo aturde y en el fondo se ven rocas volar hacia arriba. Después de un momento, caen rocas en la posición del adversario de uno en uno. Entre cada golpe da tiempo a bloquear el siguiente.
Daño: 27 x golpe inicial, 10 x rocas menores /
Cooldown: 22 seg /
Alcance: alto


### NIVEL 4:

* Explosive Willpower: Lanza unas ondas de choque de aire a ambos lados del jugador. Si impactan en el oponente le causan daño medio-bajo, con empuje altísimo que desplaza al oponente lejos del jugador.
 
Daño: 10 
Cooldown: 14
Alcance: bajo

* Nado Kick: Una patada giratoria con explosiones verdes, durante la cual el personaje levita ligeramente y tiene control absoluto de movimiento lateral. Si golpea al rival con la patada, le empuja mucho.
Daño: 2 x golpe menor, 10 x golpe mayor /
Cooldown: 18 seg /
Alcance: alto

* Flying Kicks: Lanza dos patadas voladoras, la primera al aire y la segunda al suelo, que provoca un temblor en una zona cercana al aterrizaje del jugador. Se puede elegir la dirección de éstas.
Daño: 5 x golpes menores, 17 x golpe final /
Cooldown: 20 seg /
Alcance: alto 


### NIVEL 3:

* Mina: Lanza una mina a una distancia medio-alta, que si impacta al jugador le provoca empuje, daño y noqueo bajos. Después se establece en el suelo como una mina de proximidad medio enterrada que emite una luz de detección. Si el enemigo se acerca a su rango, la mina explota, provocando un empuje medio hacia atrás del oponente y un daño medio-alto.
Daño: 1 x contacto, 10 x explosión /
Cooldown: 12 seg /
Alcance: medio

* HookShoot: Lanza gancho que si impacta con el rival lo atrae hacia él, pensado para hacer combo con golpes difíciles de dar por rango muy corto. 
Daño: 3 /
Cooldown: 12 /
Alcance: alto

* Hail Ball: Lanza un proyectil de hielo de velocidad lenta y bloqueable, que si impacta, congela al enemigo durante unos segundos, impidiendo toda clase de acción por parte del oponente.
Daño: 3 /
Tiempo congelación: 2.5 seg /
Cooldown: 15 seg /
Alcance: alto

* Knock Down: Da un placaje de aspecto verde que atraviesa la guardia del enemigo, le empuja hacia atrás y le hace algo de daño. 
Daño: 11 /
Cooldown: 15 seg /
Alcance: bajo

### NIVEL 2:

* Acid Split : Lanza una poción como proyectil, que deja una nube de veneno. Esta nube envenena al jugador enemigo y le baja la defensa temporalmente.
Daño: 10 x inicial, 2/seg x charco /
Cooldown: 13 /
Alcance: medio

* Dash: Dashea hacia delante o detrás con cooldown alto. Permite alejarse o acercarse al oponente según la situación.
Cooldown: 15 /
Alcance: medio

* Vampiric Strike: Da un golpe de poco daño que recupera un porcentaje de la barra de vida al que lo ha usado, si conecta contra el oponente. Estéticamente, una garra roja con vórtice bermejo pequeño con pinchos hacia delante, y una luz roja tenue que aparece para indicar la curación.
Daño: 5 /
Cooldown: 13 /
Alcance: bajo

* Laser Lineal: Raya de color rojo que cruza la pantalla horizontalmente, haciendo poco daño. 
Daño: 7 /
Cooldown: 12 /
Alcance: alto

### NIVEL 1:
* Shrug Off: Permite anular el daño de un ataque enemigo tras su activación. Aparece un icono encima de la cabeza del jugador que lo lanza con forma de persona indiferente.
Cooldown: 9 

* Reaching Strike: Aparece un puño gigante en dirección al oponente. 
Daño: 6 /
Cooldown: 11 /
Alcance: medio

* More Power: Al activarse, potencia el daño del siguiente golpe por un multiplicador específico. Entra en cooldown al ser activado, no al realizar el ataque potenciado. Sale un icono encima del jugador con forma de humano exaltado. 
Daño: x2 en ataque potenciado
Cooldown: 12

* Chicken Little: Lanza un pollo en diagonal descendente que persigue al oponente, que le empuja al impactar, haciendo un daño y sonido ridículos. 
Daño: 1 /
Cooldown: 9 / 
Alcance: alto

## Referencias
* Saga de Videojuegos Tekken
* Saga de Videojuegos Street Fighter
* Plants vs Zombies (f10r)  

