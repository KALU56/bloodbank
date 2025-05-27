#ifndef DONOR_H
#define DONOR_H

#include <QString>

struct Donor {
    QString id;         // Unique donor ID
    QString firstName;
    QString lastName;
    QString gender;
    QString phone;
    QString username;
    QString bloodType;
    QString region;
    QString woreda;
    QString kebele;
    QString city;
};

#endif // DONOR_H
