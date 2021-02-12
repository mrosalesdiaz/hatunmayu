#!/bin/bash
echo '#######################################################################################################################################'
set -e

psql -v ON_ERROR_STOP=1 --username "$POSTGRES_USER" --dbname "$POSTGRES_DB" <<-EOSQL
   	CREATE USER hatunmayu WITH PASSWORD 'moresecure';
    CREATE DATABASE db_hatunmayu TEMPLATE template0;
    GRANT ALL PRIVILEGES ON DATABASE db_hatunmayu TO hatunmayu;
EOSQL

psql -v ON_ERROR_STOP=1 --username "$POSTGRES_USER" --dbname "db_hatunmayu" <<-EOSQL
    CREATE SCHEMA "account" AUTHORIZATION hatunmayu;
    CREATE SCHEMA "lobby" AUTHORIZATION hatunmayu;
    CREATE SCHEMA "gameplay" AUTHORIZATION hatunmayu;
    CREATE SCHEMA "player" AUTHORIZATION hatunmayu;
    CREATE SCHEMA "shop" AUTHORIZATION hatunmayu;
    CREATE SCHEMA "ranking" AUTHORIZATION hatunmayu;
    
    -- register extensions
    CREATE EXTENSION IF NOT EXISTS "pgcrypto";
    CREATE EXTENSION IF NOT EXISTS "uuid-ossp";
    CREATE EXTENSION IF NOT EXISTS "tablefunc";

EOSQL