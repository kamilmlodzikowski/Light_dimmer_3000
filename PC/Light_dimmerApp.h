/***************************************************************
 * Name:      Light_dimmerApp.h
 * Purpose:   Defines Application Class
 * Author:    Mlodzikowski&Muszynski ()
 * Created:   2019-01-16
 * Copyright: Mlodzikowski&Muszynski ()
 * License:
 **************************************************************/

#ifndef LIGHT_DIMMERAPP_H
#define LIGHT_DIMMERAPP_H

#include <wx/app.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

class Light_dimmerApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // LIGHT_DIMMERAPP_H
