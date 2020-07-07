#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/_ext/5523a538/ICollectible.o \
	${OBJECTDIR}/_ext/5523a538/IDictionary.o \
	${OBJECTDIR}/_ext/5523a538/IKey.o \
	${OBJECTDIR}/_ext/5523a538/ListDiccIterator.o \
	${OBJECTDIR}/_ext/5523a538/ListDiccIteratorKey.o \
	${OBJECTDIR}/_ext/5523a538/ListDiccIteratorObj.o \
	${OBJECTDIR}/_ext/5523a538/Lista.o \
	${OBJECTDIR}/_ext/5523a538/ListaDicc.o \
	${OBJECTDIR}/_ext/5523a538/ListaIterator.o \
	${OBJECTDIR}/_ext/5523a538/Nodo.o \
	${OBJECTDIR}/_ext/5523a538/NodoDicc.o \
	${OBJECTDIR}/_ext/5523a538/Par.o \
	${OBJECTDIR}/Comun.o \
	${OBJECTDIR}/DtInfoP.o \
	${OBJECTDIR}/DtMenu.o \
	${OBJECTDIR}/DtProducto.o \
	${OBJECTDIR}/DtTrasnporte.o \
	${OBJECTDIR}/Empleado.o \
	${OBJECTDIR}/Fabrica.o \
	${OBJECTDIR}/Factura.o \
	${OBJECTDIR}/KeyInt.o \
	${OBJECTDIR}/KeyString.o \
	${OBJECTDIR}/Menu.o \
	${OBJECTDIR}/Mozo.o \
	${OBJECTDIR}/Producto.o \
	${OBJECTDIR}/Repartidor.o \
	${OBJECTDIR}/Sistema.o \
	${OBJECTDIR}/Venta.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laboratorio3.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laboratorio3.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/laboratorio3 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/_ext/5523a538/ICollectible.o: ../../../Desktop/ColeccionesG/ICollectible.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/ICollectible.o ../../../Desktop/ColeccionesG/ICollectible.cpp

${OBJECTDIR}/_ext/5523a538/IDictionary.o: ../../../Desktop/ColeccionesG/IDictionary.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/IDictionary.o ../../../Desktop/ColeccionesG/IDictionary.cpp

${OBJECTDIR}/_ext/5523a538/IKey.o: ../../../Desktop/ColeccionesG/IKey.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/IKey.o ../../../Desktop/ColeccionesG/IKey.cpp

${OBJECTDIR}/_ext/5523a538/ListDiccIterator.o: ../../../Desktop/ColeccionesG/ListDiccIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/ListDiccIterator.o ../../../Desktop/ColeccionesG/ListDiccIterator.cpp

${OBJECTDIR}/_ext/5523a538/ListDiccIteratorKey.o: ../../../Desktop/ColeccionesG/ListDiccIteratorKey.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/ListDiccIteratorKey.o ../../../Desktop/ColeccionesG/ListDiccIteratorKey.cpp

${OBJECTDIR}/_ext/5523a538/ListDiccIteratorObj.o: ../../../Desktop/ColeccionesG/ListDiccIteratorObj.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/ListDiccIteratorObj.o ../../../Desktop/ColeccionesG/ListDiccIteratorObj.cpp

${OBJECTDIR}/_ext/5523a538/Lista.o: ../../../Desktop/ColeccionesG/Lista.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/Lista.o ../../../Desktop/ColeccionesG/Lista.cpp

${OBJECTDIR}/_ext/5523a538/ListaDicc.o: ../../../Desktop/ColeccionesG/ListaDicc.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/ListaDicc.o ../../../Desktop/ColeccionesG/ListaDicc.cpp

${OBJECTDIR}/_ext/5523a538/ListaIterator.o: ../../../Desktop/ColeccionesG/ListaIterator.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/ListaIterator.o ../../../Desktop/ColeccionesG/ListaIterator.cpp

${OBJECTDIR}/_ext/5523a538/Nodo.o: ../../../Desktop/ColeccionesG/Nodo.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/Nodo.o ../../../Desktop/ColeccionesG/Nodo.cpp

${OBJECTDIR}/_ext/5523a538/NodoDicc.o: ../../../Desktop/ColeccionesG/NodoDicc.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/NodoDicc.o ../../../Desktop/ColeccionesG/NodoDicc.cpp

${OBJECTDIR}/_ext/5523a538/Par.o: ../../../Desktop/ColeccionesG/Par.cpp
	${MKDIR} -p ${OBJECTDIR}/_ext/5523a538
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/_ext/5523a538/Par.o ../../../Desktop/ColeccionesG/Par.cpp

${OBJECTDIR}/Comun.o: Comun.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Comun.o Comun.cpp

${OBJECTDIR}/DtInfoP.o: DtInfoP.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtInfoP.o DtInfoP.cpp

${OBJECTDIR}/DtMenu.o: DtMenu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtMenu.o DtMenu.cpp

${OBJECTDIR}/DtProducto.o: DtProducto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtProducto.o DtProducto.cpp

${OBJECTDIR}/DtTrasnporte.o: DtTrasnporte.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/DtTrasnporte.o DtTrasnporte.cpp

${OBJECTDIR}/Empleado.o: Empleado.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Empleado.o Empleado.cpp

${OBJECTDIR}/Fabrica.o: Fabrica.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Fabrica.o Fabrica.cpp

${OBJECTDIR}/Factura.o: Factura.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Factura.o Factura.cpp

${OBJECTDIR}/KeyInt.o: KeyInt.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/KeyInt.o KeyInt.cpp

${OBJECTDIR}/KeyString.o: KeyString.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/KeyString.o KeyString.cpp

${OBJECTDIR}/Menu.o: Menu.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Menu.o Menu.cpp

${OBJECTDIR}/Mozo.o: Mozo.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Mozo.o Mozo.cpp

${OBJECTDIR}/Producto.o: Producto.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Producto.o Producto.cpp

${OBJECTDIR}/Repartidor.o: Repartidor.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Repartidor.o Repartidor.cpp

${OBJECTDIR}/Sistema.o: Sistema.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sistema.o Sistema.cpp

${OBJECTDIR}/Venta.o: Venta.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Venta.o Venta.cpp

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
