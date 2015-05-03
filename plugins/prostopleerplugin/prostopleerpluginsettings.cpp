/*
 * Copyright (C) 2013-2014  Khryukin Evgeny
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#include "prostopleerpluginsettings.h"
#include "ui_prostopleerpluginsettings.h"

#include "options.h"
#include "common.h"
#include "prostopleerplugindefines.h"

class ProstopleerPluginSettings::Private
{
public:
	explicit Private(ProstopleerPluginSettings* p) :
		page_(p),
		widget_(new QWidget),
		ui(new Ui::ProstopleerPluginSettings)
	{
		ui->setupUi(widget_);
	}

	ProstopleerPluginSettings* page_;
	QWidget* widget_;
	Ui::ProstopleerPluginSettings* ui;
};

ProstopleerPluginSettings::ProstopleerPluginSettings(QObject *parent) :
	QompOptionsPage(parent)
{
	d = new Private(this);
	restoreOptions();
}

ProstopleerPluginSettings::~ProstopleerPluginSettings()
{
	delete d->ui;
	delete d;
}

QString ProstopleerPluginSettings::name() const
{
	return PROSTOPLEER_PLUGIN_NAME;
}

void ProstopleerPluginSettings::retranslate()
{
	d->ui->retranslateUi(d->widget_);
}

QObject *ProstopleerPluginSettings::page() const
{
	return d->widget_;
}

void ProstopleerPluginSettings::applyOptions()
{
	Options::instance()->setOption(PROSTOPLEER_PLUGIN_OPTION_LOGIN, d->ui->le_login->text());
	Options::instance()->setOption(PROSTOPLEER_PLUGIN_OPTION_PASSWORD, Qomp::encodePassword(d->ui->le_pass->text(), PROSTOPLEER_DECODE_KEY));
}

void ProstopleerPluginSettings::restoreOptions()
{
	d->ui->le_login->setText(Options::instance()->getOption(PROSTOPLEER_PLUGIN_OPTION_LOGIN).toString());
	d->ui->le_pass->setText(Qomp::decodePassword(Options::instance()->getOption(PROSTOPLEER_PLUGIN_OPTION_PASSWORD).toString(), PROSTOPLEER_DECODE_KEY));
}
