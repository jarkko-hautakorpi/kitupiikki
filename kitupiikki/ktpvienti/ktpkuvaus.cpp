/*
   Copyright (C) 2017 Arto Hyvättinen

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ktpkuvaus.h"
#include "ui_ktpkuvaus.h"

#include "db/kirjanpito.h"

KtpKuvaus::KtpKuvaus() :
    ui(new Ui::KtpKuvaus)
{
    ui->setupUi(this);
    setTitle("Tilikartan kuvaus");

    registerField("kuvaus", ui->kuvausEdit);
    ui->kuvausEdit->setText(kp()->asetukset()->asetus("TilikarttaKuvaus"));
}

KtpKuvaus::~KtpKuvaus()
{
    delete ui;
}

bool KtpKuvaus::validatePage()
{
    setField("kuvaus", ui->kuvausEdit->toHtml());
    return true;
}

