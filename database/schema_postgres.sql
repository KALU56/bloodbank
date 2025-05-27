
-- -- Connect to the database
-- \c BloodBankSystem

-- -- Create donors table
-- CREATE TABLE donors (
--     id VARCHAR(36) PRIMARY KEY, -- UUID for unique donor ID
--     first_name VARCHAR(50) NOT NULL,
--     last_name VARCHAR(50) NOT NULL,
--     gender VARCHAR(10),
--     phone VARCHAR(15),
--     username VARCHAR(50) UNIQUE NOT NULL,
--     blood_type VARCHAR(3),
--     region VARCHAR(50),
--     woreda VARCHAR(50),
--     kebele VARCHAR(50),
--     city VARCHAR(50),
--     password VARCHAR(255) NOT NULL -- Store hashed passwords in production
-- );

-- -- Create supervisors table
-- CREATE TABLE supervisors (
--     id SERIAL PRIMARY KEY,
--     username VARCHAR(50) UNIQUE NOT NULL,
--     password VARCHAR(255) NOT NULL -- Store hashed passwords in production
-- );

-- -- Create medical_history table
-- CREATE TABLE medical_history (
--     id SERIAL PRIMARY KEY,
--     donor_id VARCHAR(36) REFERENCES donors(id),
--     hiv_status BOOLEAN NOT NULL,
--     syphilis_status BOOLEAN NOT NULL,
--     hepatitis_status BOOLEAN NOT NULL,
--     sugar_level FLOAT,
--     message TEXT
-- );

-- -- Create health_history table
-- CREATE TABLE health_history (
--     id SERIAL PRIMARY KEY,
--     donor_id VARCHAR(36) REFERENCES donors(id),
--     date VARCHAR(10), -- Consider DATE type for better handling
--     weight FLOAT,
--     blood_pressure VARCHAR(10),
--     sugar_level FLOAT,
--     start_time VARCHAR(8),
--     end_time VARCHAR(8)
-- );

-- -- Insert a sample supervisor for testing
-- INSERT INTO supervisors (username, password) VALUES ('admin', 'admin123');
