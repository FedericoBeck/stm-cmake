# STM32F103 CMake Template

Este repositorio contiene un template para configurar y compilar proyectos para la placa STM32F103 utilizando CMake. Está diseñado para desarrolladores que prefieren un entorno ligero y flexible para sus proyectos de sistemas embebidos, utilizando herramientas como `clang` y `stlink`.

## Requisitos

- [CMake](https://cmake.org/download/) 3.12 o superior
- [Clang](https://clang.llvm.org/)
- [STLink](https://github.com/texane/stlink) tool
> **Nota:** Para obtener instrucciones detalladas sobre cómo instalar la herramienta `stlink`, visita su [repositorio oficial](https://github.com/texane/stlink).
## Instrucciones

### Configuración del Proyecto

1. Clona el repositorio:

    ```bash
    git clone <https://github.com/FedericoBeck/stm-cmake.github>
    cd <stm-cmake>
    ```

2. Ejecuta el siguiente comando para generar los archivos de configuración de CMake:

    ```bash
    cmake -B build -S .
    ```

    Esto creará un directorio `build` con todos los archivos necesarios para la compilación.

3. Dentro del directorio `build`, ejecuta el siguiente comando para generar el archivo `compile_commands.json`:

    ```bash
    cd build
    cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    ```

    Este archivo es crucial para integrar el proyecto con `clang` y permitir la correcta resolución de las librerías utilizadas.

### Compilación

1. Dentro del directorio `build`, ejecuta el comando:

    ```bash
    make
    ```

    Esto compilará el proyecto y generará los archivos de salida necesarios.

### Flasheo del Microcontrolador

1. Utiliza la herramienta `stlink` para flashear el binario generado en la STM32F103:

    ```bash
    st-flash --reset write <archivo-bin> 0x8000000
    ```

    Asegúrate de conectar correctamente tu placa STM32F103 y de que el archivo `.bin` generado esté en el directorio adecuado.

## Estructura del Proyecto

- `src/`: Contiene el código fuente del proyecto.
- `include/`: Contiene los archivos de cabecera.
- `build/`: Directorio generado automáticamente para los archivos de compilación.
- `CMakeLists.txt`: Archivo de configuración de CMake.

## Contribuciones

Las contribuciones son bienvenidas. Si encuentras un problema o tienes una sugerencia para mejorar este template, no dudes en abrir un issue o un pull request.

## Licencia
Este proyecto está licenciado bajo la [MIT License](LICENSE).

