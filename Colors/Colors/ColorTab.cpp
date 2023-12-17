#include "ColorTab.h"

std::string inttohex(int a)
{
	std::string tmp("");
	do
	{
		int r(a % 16);
		if (r > 9)
		{
			r += (int)'A' - 10;
		}
		else
		{
			r += (int)'0';
		};
		tmp = (char)r + tmp;
		a /= 16;
	} while (a);
	return tmp;
}

ColorTab::ColorTab(QWidget* parent, const QString colorName_, const int pos_) : QWidget(parent)
{
	colorName = colorName_;
	pos = pos_;
	QHBoxLayout* hLayout1 = new QHBoxLayout(this);
	QVBoxLayout* vLayout1 = new QVBoxLayout(this);
	QVBoxLayout* vLayout2 = new QVBoxLayout(this);

	hLayout1->addLayout(vLayout1);
	hLayout1->addLayout(vLayout2);

	first = second = third = fourth = 0;

	QLabel* colorLabel = new QLabel(colorName);

	colorButton = new QPushButton(this);
	colorButton->setStyleSheet("background-color: #000000;");
	connect(colorButton, SIGNAL(clicked()), this, SLOT(onButtonPress()));
	vLayout1->addWidget(colorLabel);
	vLayout1->addWidget(colorButton);

	b1 = new QSpinBox(this);
	b2 = new QSpinBox(this);
	b3 = new QSpinBox(this);
	b4 = new QSpinBox(this);

	connect(b1, SIGNAL(valueChanged(int)), this, SLOT(onSlider1(int)));
	connect(b2, SIGNAL(valueChanged(int)), this, SLOT(onSlider2(int)));
	connect(b3, SIGNAL(valueChanged(int)), this, SLOT(onSlider3(int)));

	b1->setSingleStep(1);
	b2->setSingleStep(1);
	b3->setSingleStep(1);
	if (colorName == "CMYK")
	{
		b1->setRange(0, 100);
		b2->setRange(0, 100);
		b3->setRange(0, 100);
		b4->setRange(0, 100);
		b4->setSingleStep(1);
		connect(b4, SIGNAL(valueChanged(int)), this, SLOT(onSlider4(int)));
	}
	else if(colorName == "RGB")
	{
		b1->setRange(0, 255);
		b2->setRange(0, 255);
		b3->setRange(0, 255);
	}
	else if (colorName == "HSL") 
	{
		b1->setRange(0, 360);
		b2->setRange(0, 100);
		b3->setRange(0, 100);
	}
	else if (colorName == "HSL" || colorName == "HSV")
	{
		b1->setRange(0, 360);
		b2->setRange(0, 100);
		b3->setRange(0, 100);
	}
	else if (colorName == "XYZ") 
	{
		b1->setRange(0, 100);
		b2->setRange(0, 100);
		b3->setRange(0, 100);
	}
	else if (colorName == "LAB")
	{
		b1->setRange(0, 100);
		b2->setRange(-128, 128);
		b3->setRange(-128, 128);

	}
	else
	{
		throw "unknown model";
	}
	vLayout2->addWidget(b1);
	vLayout2->addWidget(b2);
	vLayout2->addWidget(b3);
	b4->hide();

	if (colorName == "CMYK") 
	{
		vLayout2->addWidget(b4);
		b4->show();
	}
}

void ColorTab::changeColor()
{
	b1->blockSignals(true);
	b2->blockSignals(true);
	b3->blockSignals(true);
	b4->blockSignals(true);
	b1->setValue(first);
	b2->setValue(second);
	b3->setValue(third);
	b4->setValue(fourth);
	b1->blockSignals(false);
	b2->blockSignals(false);
	b3->blockSignals(false);
	b4->blockSignals(false);
}

void ColorTab::changeColor(double c1, double c2, double c3, double c4)
{
	first = c1;
	second = c2;
	third = c3;
	fourth = c4;
	changeColor();
}

void ColorTab::changeColor(QList<double> lst)
{
	if (colorName == "CMYK") 
	{
		changeColor(lst[0], lst[1], lst[2], lst[3]);
	}
	else
	{
		changeColor(lst[0], lst[1], lst[2]);
	}
}

QList<double> ColorTab::getColor()
{
	QList<double> l = { first, second, third, fourth };
	return l;
}

QList<double> ColorTab::getButtonColor()
{
	QColor color = colorButton->palette().color(QPalette::Button);
	return { (double)color.red(), (double)color.green(), (double)color.blue() };
}

QString ColorTab::getColorName()
{
	return colorName;
}

void ColorTab::setBoxColor(double red, double green, double blue)
{
	std::string r = inttohex((int)red);
	std::string g = inttohex((int)green);
	std::string b = inttohex((int)blue);
	
	if (r.size() < 2)
	{
		r = "0" + r;
	}
	if (g.size() < 2)
	{
		g = "0" + g;
	}
	if (b.size() < 2)
	{
		b = "0" + b;
	}

	QString hex = QString::fromStdString(r + g + b);
	colorButton->setStyleSheet("background-color: #" + hex + "; ");
}

ColorTab::~ColorTab()
{

}

void ColorTab::onSlider1(int value)
{
	first = value;
	emit colorChange(pos, 0);
}

void ColorTab::onSlider2(int value)
{
	second = value;
	emit colorChange(pos, 0);
}

void ColorTab::onSlider3(int value)
{
	third = value;
	emit colorChange(pos, 0);
}

void ColorTab::onSlider4(int value)
{
	fourth = value;
	emit colorChange(pos, 0);
}


void ColorTab::onButtonPress() 
{
	QColorDialog dialog;
	dialog.exec();

	QColor color = dialog.selectedColor();

	setBoxColor(color.red(), color.green(), color.blue());

	emit colorChange(pos, 1);
}

