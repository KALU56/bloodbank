CREATE TABLE donors ( id SERIAL PRIMARY KEY, first_name VARCHAR(50) NOT NULL, last_name VARCHAR(50) NOT NULL, gender VARCHAR(10) CHECK (gender IN ('Male', 'Female')), phone VARCHAR(15), username VARCHAR(50) UNIQUE NOT NULL, password VARCHAR(255) NOT NULL, blood_type VARCHAR(3) CHECK (blood_type IN ('A+', 'A-', 'B+', 'B-', 'AB+', 'AB-', 'O+', 'O-')), region VARCHAR(100), woreda VARCHAR(100), kebele VARCHAR(100), city VARCHAR(100) );

CREATE TABLE medical_history ( id SERIAL PRIMARY KEY, donor_id INTEGER REFERENCES donors(id), hiv_status BOOLEAN NOT NULL, syphilis_status BOOLEAN NOT NULL, hepatitis_status BOOLEAN NOT NULL, sugar_level FLOAT, message TEXT, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP );

CREATE TABLE health_history ( id SERIAL PRIMARY KEY, donor_id INTEGER REFERENCES donors(id), record_date DATE NOT NULL, weight FLOAT, blood_pressure VARCHAR(20), sugar_level FLOAT, start_time TIME, end_time TIME, created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP );

CREATE TABLE supervisors ( id SERIAL PRIMARY KEY, username VARCHAR(50) UNIQUE NOT NULL, password VARCHAR(255) NOT NULL );
