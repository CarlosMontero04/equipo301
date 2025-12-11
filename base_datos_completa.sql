/*M!999999\- enable the sandbox mode */ 
-- MariaDB dump 10.19  Distrib 10.11.13-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: gestion_tutorias
-- ------------------------------------------------------
-- Server version	10.11.13-MariaDB-0ubuntu0.24.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `alertas`
--

DROP TABLE IF EXISTS `alertas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `alertas` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_estudiante` int(11) NOT NULL,
  `id_tutor` int(11) NOT NULL,
  `tipo_riesgo` varchar(50) DEFAULT NULL,
  `descripcion` text DEFAULT NULL,
  `fecha` datetime DEFAULT current_timestamp(),
  `estado` varchar(20) DEFAULT 'Pendiente',
  PRIMARY KEY (`id`),
  KEY `id_estudiante` (`id_estudiante`),
  KEY `id_tutor` (`id_tutor`),
  CONSTRAINT `alertas_ibfk_1` FOREIGN KEY (`id_estudiante`) REFERENCES `estudiantes` (`id`),
  CONSTRAINT `alertas_ibfk_2` FOREIGN KEY (`id_tutor`) REFERENCES `tutores` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `alertas`
--

LOCK TABLES `alertas` WRITE;
/*!40000 ALTER TABLE `alertas` DISABLE KEYS */;
/*!40000 ALTER TABLE `alertas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asignaciones`
--

DROP TABLE IF EXISTS `asignaciones`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `asignaciones` (
  `id_asignacion` int(11) NOT NULL AUTO_INCREMENT,
  `id_estudiante` int(11) DEFAULT NULL,
  `id_tutor` int(11) DEFAULT NULL,
  `fecha_inicio` datetime DEFAULT current_timestamp(),
  `fecha_fin` datetime DEFAULT NULL,
  `estado` varchar(20) DEFAULT 'Activa',
  `curso_academico` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`id_asignacion`),
  KEY `id_estudiante` (`id_estudiante`),
  KEY `id_tutor` (`id_tutor`),
  CONSTRAINT `asignaciones_ibfk_1` FOREIGN KEY (`id_estudiante`) REFERENCES `estudiantes` (`id`),
  CONSTRAINT `asignaciones_ibfk_2` FOREIGN KEY (`id_tutor`) REFERENCES `tutores` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asignaciones`
--

LOCK TABLES `asignaciones` WRITE;
/*!40000 ALTER TABLE `asignaciones` DISABLE KEYS */;
/*!40000 ALTER TABLE `asignaciones` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `coordinadores`
--

DROP TABLE IF EXISTS `coordinadores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `coordinadores` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `email_uco` varchar(100) DEFAULT NULL,
  `password` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `coordinadores`
--

LOCK TABLES `coordinadores` WRITE;
/*!40000 ALTER TABLE `coordinadores` DISABLE KEYS */;
INSERT INTO `coordinadores` VALUES
(1,'admin@uco.es','admin');
/*!40000 ALTER TABLE `coordinadores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `estudiantes`
--

DROP TABLE IF EXISTS `estudiantes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `estudiantes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(100) NOT NULL,
  `email_uco` varchar(100) DEFAULT NULL,
  `titulacion` varchar(100) DEFAULT NULL,
  `curso` int(11) DEFAULT NULL,
  `promedio` decimal(4,2) DEFAULT NULL,
  `id_tutor` int(11) DEFAULT NULL,
  `password` varchar(50) DEFAULT '1234',
  PRIMARY KEY (`id`),
  KEY `id_tutor` (`id_tutor`),
  CONSTRAINT `estudiantes_ibfk_1` FOREIGN KEY (`id_tutor`) REFERENCES `tutores` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=36 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `estudiantes`
--

LOCK TABLES `estudiantes` WRITE;
/*!40000 ALTER TABLE `estudiantes` DISABLE KEYS */;
INSERT INTO `estudiantes` VALUES
(1,'Aaron (Ing-1)','aaron@uco.es','Ingenieria',1,9.50,NULL,'1234'),
(2,'Berta (Ing-1)','berta@uco.es','Ingenieria',1,8.20,NULL,'1234'),
(3,'Carlos (Ing-4)','carlos@uco.es','Ingenieria',4,7.50,NULL,'1234'),
(4,'Diana (Ing-1)','diana@uco.es','Ingenieria',1,6.00,NULL,'1234'),
(5,'Eloy (Ing-2)','eloy@uco.es','Ingenieria',2,5.50,NULL,'1234'),
(6,'Fanny (Ing-3)','fanny@uco.es','Ingenieria',3,9.00,NULL,'1234'),
(7,'Goku (Ing-1)','goku@uco.es','Ingenieria',1,8.80,NULL,'1234'),
(8,'Hulk (Ing-1)','hulk@uco.es','Ingenieria',1,7.00,NULL,'1234'),
(9,'IronMan (Ing-4)','Tony@uco.es','Ingenieria',4,9.90,NULL,'1234'),
(10,'Jarvis (Ing-2)','jarvis@uco.es','Ingenieria',2,6.50,NULL,'1234'),
(11,'Kevin (Ing-1)','kevin@uco.es','Ingenieria',1,5.00,NULL,'1234'),
(12,'Luisa (Ing-1)','luisa@uco.es','Ingenieria',1,7.20,NULL,'1234'),
(13,'Mario (Ing-3)','mario@uco.es','Ingenieria',3,6.80,NULL,'1234'),
(14,'Nuria (Ing-1)','nuria@uco.es','Ingenieria',1,8.10,NULL,'1234'),
(15,'Omar (Der-1)','omar@uco.es','Derecho',1,8.50,NULL,'1234'),
(16,'Pau (Der-1)','pau@uco.es','Derecho',1,7.50,NULL,'1234'),
(17,'Quique (Der-2)','quique@uco.es','Derecho',2,6.50,NULL,'1234'),
(18,'Rosa (Der-3)','rosa@uco.es','Derecho',3,9.20,NULL,'1234'),
(19,'Sara (Der-1)','sara@uco.es','Derecho',1,5.50,NULL,'1234'),
(20,'Tito (Der-4)','tito@uco.es','Derecho',4,6.00,NULL,'1234'),
(21,'Ursula (Der-1)','ursula@uco.es','Derecho',1,7.80,NULL,'1234'),
(22,'Vanesa (Der-2)','vane@uco.es','Derecho',2,8.90,NULL,'1234'),
(23,'Walter (Med-1)','walter@uco.es','Medicina',1,9.80,NULL,'1234'),
(24,'Xena (Med-1)','xena@uco.es','Medicina',1,9.50,NULL,'1234'),
(25,'Yago (Med-1)','yago@uco.es','Medicina',1,9.00,NULL,'1234'),
(26,'Zoe (Med-2)','zoe@uco.es','Medicina',2,8.50,NULL,'1234'),
(27,'Alex (Med-3)','alex@uco.es','Medicina',3,7.00,NULL,'1234'),
(28,'Bea (Cien-1)','bea@uco.es','Ciencias',1,8.00,NULL,'1234'),
(29,'Ciro (Cien-1)','ciro@uco.es','Ciencias',1,7.00,NULL,'1234'),
(30,'Dani (Cien-2)','dani2@uco.es','Ciencias',2,6.00,NULL,'1234'),
(31,'Eva (Cien-3)','eva2@uco.es','Ciencias',3,9.50,NULL,'1234'),
(32,'Flor (Cien-4)','flor@uco.es','Ciencias',4,5.00,NULL,'1234'),
(33,'Platon (Fil-1)','platon@uco.es','Filosofia',1,10.00,NULL,'1234'),
(34,'Socrates (Fil-2)','socr@uco.es','Filosofia',2,9.00,NULL,'1234'),
(35,'Nietzsche (Fil-4)','nietz@uco.es','Filosofia',4,5.00,NULL,'1234');
/*!40000 ALTER TABLE `estudiantes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `mensajes`
--

DROP TABLE IF EXISTS `mensajes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `mensajes` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `id_emisor` int(11) NOT NULL,
  `rol_emisor` varchar(20) DEFAULT NULL,
  `id_receptor` int(11) NOT NULL,
  `rol_receptor` varchar(20) DEFAULT NULL,
  `contenido` text NOT NULL,
  `fecha` datetime DEFAULT current_timestamp(),
  `leido` tinyint(1) DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `mensajes`
--

LOCK TABLES `mensajes` WRITE;
/*!40000 ALTER TABLE `mensajes` DISABLE KEYS */;
/*!40000 ALTER TABLE `mensajes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tutores`
--

DROP TABLE IF EXISTS `tutores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8mb4 */;
CREATE TABLE `tutores` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `nombre` varchar(100) NOT NULL,
  `departamento` varchar(100) DEFAULT NULL,
  `cupo_maximo` int(11) DEFAULT 5,
  `cupo_actual` int(11) DEFAULT 0,
  `password` varchar(50) DEFAULT '1234',
  `email_uco` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tutores`
--

LOCK TABLES `tutores` WRITE;
/*!40000 ALTER TABLE `tutores` DISABLE KEYS */;
INSERT INTO `tutores` VALUES
(1,'Prof. Alan Turing','Ingenieria',5,0,'1234','turing@uco.es'),
(2,'Prof. Nikola Tesla','Ingenieria',4,0,'1234','tesla@uco.es'),
(3,'Prof. Ada Lovelace','Ingenieria',4,0,'1234','ada@uco.es'),
(4,'Prof. Montesquieu','Derecho',5,0,'1234','monte@uco.es'),
(5,'Prof. Cicerón','Derecho',5,0,'1234','cice@uco.es'),
(6,'Dr. House','Medicina',2,0,'1234','house@uco.es'),
(7,'Prof. Marie Curie','Ciencias',4,0,'1234','curie@uco.es'),
(8,'Prof. Einstein','Ciencias',4,0,'1234','albert@uco.es');
/*!40000 ALTER TABLE `tutores` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-12-11 21:48:34
