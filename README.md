
## TP2: Uso de Interfaces

<details>
<summary><b>Información acerca de proyecto</b></summary>
  
* **Autores:**
    * Pojmaevich Mirko (mirkopoj@gmail.com) 
    * Torletti Lara (lara.a.torletti@gmail.com)

* **Materia:**
    Arquitectura de Software - B5647

* **Profesor:**
    Martín Morixe
  
* Universidad Nacional de Río Negro - Sede Andina - Ingeniería Electrónica
</details>

<details>

<summary><b>Objetivo de proyecto</b></summary>

* Diseñar e implementar un programa que tenga un interfaz pila (StackInterface) y dos implementaciones:
  * una con memoria estática (FixedArrayStack) 
  * otra con memoria dinámica (DynamicMemStack)
   
* Escribir una clase Vehiculo que sea apilable.
* Escribir una clase StackUser que use la pila:
  * método para cargar la pila
  * método para consumir los elementos e imprimir sus datos
    
![Consigna](/consigna/imagenconsigna.png)
 </details>
 
<details>
  
<summary><b>Instrucciones de uso</b></summary>

* Haga:
 ```{bash}
git clone https://github.com/Arquitectura-de-Software-UNRN-2024/TP2-Uso-de-interfaces.git
make
```
* Los ejecutables luego de hacer make, se encontrarán en bin/.
* para correr el Stackable main:
 ```{bash}
#Para correr el stackable main con los vehiculos
bin/main <opciones>
# en donde las opciones son:
#
# --help | -h : para mostrar ayuda.
#
# -f : selecciona la implementación de pila estática.
#  La pila se crea con un tamaño predeterminado definido por la variable
#  `FIXED_ARRAY_STACK_CAPACITY` en el archivo ´fixed_array_stack.hpp`.
#
# -d [tamaño] : selecciona la implementación de pila de memoria dinámica.
#  Si no se proporciona un tamaño, se crea una pila predeterminada con un tamaño
#  especificado por la constante `DYNAMIC_STACK_INITIAL_CAPACITY` en el archivo `dynamic_mem_stack.hpp`.
#  Si se proporciona un tamaño (por ejemplo, `-d 100`), la pila se inicializa con la capacidad inicial especificada.
#
# -r [tamaño] : selecciona la implementación de pila de memoria dinámica redimensionable.
#  Si no se proporciona un tamaño, se crea una pila predeterminada con un tamaño especificado
#  por la constante `DYNAMIC_STACK_INITIAL_CAPACITY` en el archivo `dynamic_mem_stack.hpp`.
#  Si se proporciona un tamaño (por ejemplo, `-r 100`), la pila se inicializa con la capacidad inicial especificada.
```

</details>

<details>
  
<summary><b>Pruebas de programa funcionando</b></summary>

### Menú de ayuda
  <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/menuhelp.png alt="Menú de Ayuda" width="500px">
  </p>
  </div>
  
### Código main
 <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/maincpp.png alt="Código main" width="500px">
  </p>
  </div>

### Flag -f  
#### Fixed Array Stack con el 'define' por default y 'define' autodefinido por usuario
 <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/flag-fcondistintasdefiniciones.png alt="Flag-f" width="500px">
  </p>
  </div>

### Flag -d  
#### Dinamic Array Stack con el 'define' por default y con [tamaño] definido por usuario por teclado
 <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/flag-dcondistintasdef.png alt="Flag-d" width="500px">
  </p>
  </div>


### Flag -r  
#### Dinamic Array Stack Rezizable con el 'define' por default y con [tamaño] definido por usuario por teclado
 <div>
  <p style = 'text-align:center;'>
  <img src=/consigna/flag-rcondistintasdefiniciones.png alt="Flag-r" width="500px">
  </p>
  </div>

</details>

> [!WARNING]
> Correr los test depende de Criterion. [Ver más sobre criterion](https://criterion.readthedocs.io/en/master/intro.html)

