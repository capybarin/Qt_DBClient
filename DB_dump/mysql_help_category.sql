CREATE DATABASE  IF NOT EXISTS `mysql` /*!40100 DEFAULT CHARACTER SET latin1 */;
USE `mysql`;
-- MySQL dump 10.13  Distrib 5.5.16, for Win32 (x86)
--
-- Host: 127.0.0.1    Database: mysql
-- ------------------------------------------------------
-- Server version	5.5.62

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `help_category`
--

DROP TABLE IF EXISTS `help_category`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `help_category` (
  `help_category_id` smallint(5) unsigned NOT NULL,
  `name` char(64) NOT NULL,
  `parent_category_id` smallint(5) unsigned DEFAULT NULL,
  `url` text NOT NULL,
  PRIMARY KEY (`help_category_id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='help categories';
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `help_category`
--

LOCK TABLES `help_category` WRITE;
/*!40000 ALTER TABLE `help_category` DISABLE KEYS */;
INSERT INTO `help_category` VALUES (1,'Geographic',0,''),(2,'Polygon properties',35,''),(3,'Numeric Functions',39,''),(4,'WKT',35,''),(5,'Plugins',36,''),(6,'Control flow functions',39,''),(7,'MBR',35,''),(8,'Transactions',36,''),(9,'Help Metadata',36,''),(10,'Account Management',36,''),(11,'Point properties',35,''),(12,'Encryption Functions',39,''),(13,'LineString properties',35,''),(14,'Miscellaneous Functions',39,''),(15,'Logical operators',39,''),(16,'Functions and Modifiers for Use with GROUP BY',36,''),(17,'Information Functions',39,''),(18,'Storage Engines',36,''),(19,'Bit Functions',39,''),(20,'Comparison operators',39,''),(21,'Table Maintenance',36,''),(22,'User-Defined Functions',36,''),(23,'Data Types',36,''),(24,'Compound Statements',36,''),(25,'Geometry constructors',35,''),(26,'GeometryCollection properties',1,''),(27,'Administration',36,''),(28,'Data Manipulation',36,''),(29,'Utility',36,''),(30,'Language Structure',36,''),(31,'Geometry relations',35,''),(32,'Date and Time Functions',39,''),(33,'WKB',35,''),(34,'Procedures',36,''),(35,'Geographic Features',36,''),(36,'Contents',0,''),(37,'Geometry properties',35,''),(38,'String Functions',39,''),(39,'Functions',36,''),(40,'Data Definition',36,'');
/*!40000 ALTER TABLE `help_category` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-10-16 21:10:10
