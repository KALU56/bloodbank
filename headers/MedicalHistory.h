#ifndef MEDICALHISTORY_H
#define MEDICALHISTORY_H

#include <QString>

struct MedicalHistory {
    QString donorId;
    bool hivStatus;
    bool syphilisStatus;
    bool hepatitisStatus;
    float sugarLevel;
    QString message;
};

#endif // MEDICALHISTORY_H
