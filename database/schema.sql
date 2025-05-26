CREATE TABLE donors (
    username VARCHAR PRIMARY KEY,
    first_name VARCHAR,
    last_name VARCHAR,
    gender VARCHAR,
    phone VARCHAR,
    blood_type VARCHAR,
    region VARCHAR,
    worda VARCHAR,
    kebela VARCHAR,
    city VARCHAR,
    password VARCHAR
);

CREATE TABLE medical_history (
    id SERIAL PRIMARY KEY,
    username VARCHAR REFERENCES donors(username),
    hiv_status VARCHAR,
    syphilis_status VARCHAR,
    hepatitis_status VARCHAR,
    sugar_level NUMERIC,
    message TEXT
);

CREATE TABLE health_history (
    id SERIAL PRIMARY KEY,
    username VARCHAR REFERENCES donors(username),
    date DATE,
    weight NUMERIC,
    blood_pressure VARCHAR,
    sugar_level NUMERIC,
    start_time TIME,
    end_time TIME
);
