#include <QtGui>
#include <QDebug>
#include <QApplication>
#include <QInputDialog>
#include <QTime>
#include <QtGlobal>
#include <QMessageBox>

int main (int argc, char* argv[])
{
    QApplication app(argc, argv);

    QString userFullName = QInputDialog::getText(0, "User Full Name", "Enter your name and surname (first name last name)");
    QStringList userInfo = userFullName.split(" ");
    QString password;

    QString firstName = userInfo[0].trimmed();
    QString lastName = userInfo[1].trimmed();



    int userL = userFullName.length();
    if (userL < 5)
    {
        for (int i = userL; i < 5; i++)
        {
            int n = randInt('a', 'z');
            QString buf;
            buf.sprintf("%c", n);
            FullName += buf;
        }
    }

    QString FullName = firstName.toLower() + lastName.toLower();

    if (FullName.size() < 5)
    {
        FullName.insert(4,"0");
    }

    int userL = FullName.length();

    for (int i = 0; i < 5; i++)
    {
        int num = randInt(0,userL);
        password[i] = FullName[num];
    }

    if(userInfo.size() >= 2)
    {
        QString lastNameChars;
        QString firstNameChars;

        if (lastName.size() >= 4)
        {
            QString firstL = QString(lastName.at(0));
            firstL.toUpper();
            QString secondL = QString(lastName.at(1));
            secondL.toLower();
            QString thirdL = QString(lastName.at(2));
            thirdL.toLower();
            QString fourthL = QString(lastName.at(3));
            fourthL.toLower();
            lastNameChars = firstL + secondL + thirdL + fourthL;
            firstNameChars = QString(firstName.at(0));
        }
        else if (lastName.size() == 3)
        {
            QString firstL = QString(lastName.at(0));
            firstL.toUpper();
            QString secondL = QString(lastName.at(1));
            secondL.toLower();
            QString thirdL = QString(lastName.at(2));
            thirdL.toLower();
            lastNameChars = firstL + secondL + thirdL;
            firstNameChars = QString(firstName.at(0)) +
                             QString(firstName.at(1));
        }
        else if (lastName.size() == 2 )
        {
            QString firstL = QString(lastName.at(0));
            firstL.toUpper();
            QString secondL = QString(lastName.at(1));
            secondL.toLower();
            lastNameChars = firstL + secondL;
            firstNameChars = QString(firstName.at(0)) + QString(firstName.at(1)) + QString(firstName.at(2));
        }
        else if (lastName.size() == 1 )
        {
            QString firstL = QString(lastName.at(0));
            firstL.toUpper();
            lastNameChars = firstL;
            firstNameChars = QString(firstName.at(0)) + QString(firstName.at(1)) + QString(firstName.at(2)) + QString(firstName.at(3));
        }

        QString UserName = lastNameChars + firstNameChars.toLower();

        QString response = QString("The password is %1 for %2 %3 and the  username is %4 and the full name is %5").arg(password).arg(firstName).arg(lastName).arg(UserName).arg(FullName);
        QMessageBox::information(0, "Results", response);
    }
    else
    {
        QMessageBox::information(0, "Error", "Incorrect input data");
    }

    return 0;
}
