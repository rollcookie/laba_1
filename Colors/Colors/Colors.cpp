#include "Colors.h"

using std::max;
using std::min;

double NRGB(double number)
{
	if (number >= 0.0031308)
	{
		return std::max(std::min(1.055 * pow(number, 1. / 2.4) - 0.055, 1.), 0.);
	}

	return std::max(std::min(number * 12.92, 1.), 0.);
}

double NXYZ(double number)
{
	if (number >= 0.04045)
	{
		return pow((number + 0.055) / 1.055, 2.4);
	}

	return number / 12.92;
}

double FXYZ(double number) 
{
	double k = 903.3;
	double e = 0.008856;

	if (number > e) 
	{
		return pow(number, 1. / 3);
	}

	return (k * number + 16) / 116;
}

double FLAB(double number)
{
	double k = 903.3;
	double e = 0.008856;

	if (number * number * number > e)
	{
		return pow(number, 3);
	}

	return (k * number + 16) / 116;
}

QList<double> calcColor(QString c1, QString c2, QList<double> numbers)
{
	if (c1 == c2)
	{
		return numbers;
	}

	if (c1 == "HSL" && c2 == "RGB")
	{
		double H = numbers[0];
		double S = numbers[1] / 100;
		double L = numbers[2] / 100;
		double d = S * (1 - abs(2 * L - 1));
		double m = 255 * (L - 1. / 2 * d);
		double mod2 = H / 60;
		while (mod2 >= 2)
		{
			mod2 -= 2;
		}
		double x = d * round(1 - abs(mod2 - 1));

		if (H < 60)
		{
			return { 255 * d + m, 255 * x + m, m };
		}
		else if (H < 120)
		{
			return { 255 * x + m, 255 * d + m, m };
		}
		else if (H < 180)
		{
			return { m, 255 * d + m, 255 * x + m };
		}
		else if (H < 240)
		{
			return { m, 255 * x + m, 255 * d + m };
		}
		else if (H < 300)
		{
			return { 255 * x + m, m, 255 * d + m };
		}
		else if (H <= 360)
		{
			return { 255 * d + m, m, 255 * x + m };
		}

		throw "Hue is out if range";
	}
	if (c1 == "RGB" && c2 == "HSL")
	{
		double r = numbers[0];
		double g = numbers[1];
		double b = numbers[2];

		double CMax = (double)max(max(r, g), b) / 255;
		double CMin = (double)min(min(r, g), b) / 255;
		double delta = CMax - CMin;

		double M = 0;
		double m = 255;
		for (int i = 0; i < 3; i++)
		{
			if (numbers[i] > M)
			{
				M = numbers[i];
			}

			if (numbers[i] < m)
			{
				m = numbers[i];
			}
		}

		double d = (M - m) / 255;

		double L = (M + m) / 510;
		double S;

		if (L == 0)
		{
			S = 0;
		}
		else if (L > 0)
		{
			S = d / (1 - abs(2 * L - 1));
		}

		double h;

		if (delta == 0)
		{
			h = 0;
		}
		if (r >= g && r >= b)
		{
			h = 60 * (int)((g / 255 - b / 255) / delta) % 6;
		}
		else if (g >= r && g >= b)
		{
			h = 60 * ((b / 255 - r / 255) / delta + 2);
		}
		else
		{
			h = 60 * ((r / 255 - g / 255) / delta + 4);
		}

		return { h ,S * 100 ,L * 100 };
	}

	if (c1 == "HSV" && c2 == "RGB")
	{
		double H = numbers[0];
		double S = numbers[1];
		double V = numbers[2];
		int hi = (int)(H / 60) % 6;
		double Vmin = (100 - S) * V / 100;
		double a = (V - Vmin) * ((int)H % 60) / 60;
		double Vinc = Vmin + a;
		double Vdec = V - a;

		if (hi == 0)
		{
			return { 255 / 100 * V, 255 / 100 * Vinc, 255 / 100 * Vmin };
		}
		if (hi == 1)
		{
			return { 255 / 100 * Vdec, 255 / 100 * V, 255 / 100 * Vmin };
		}
		if (hi == 2)
		{
			return { 255 / 100 * Vmin, 255 / 100 * V, 255 / 100 * Vinc };
		}
		if (hi == 3)
		{
			return { 255 / 100 * Vmin, 255 / 100 * Vdec, 255 / 100 * V };
		}
		if (hi == 4)
		{
			return { 255 / 100 * Vinc, 255 / 100 * Vmin, 255 / 100 * V };
		}
		if (hi == 5)
		{
			return { 255 / 100 * V, 255 / 100 * Vmin, 255 / 100 * Vdec };
		}
	}
	if (c1 == "RGB" && c2 == "HSV")
	{
		double r = numbers[0];
		double g = numbers[1];
		double b = numbers[2];

		double CMax = (double)max(max(r, g), b) / 255;
		double CMin = (double)min(min(r, g), b) / 255;

		double v = CMax * 100;
		double s;
		if (CMax == 0)
		{
			s = 0;
		}
		else
		{
			s = (CMax - CMin) / CMax;
		}
		double delta = CMax - CMin;
		double h;

		if (delta == 0) 
		{
			h = 0;
		}
		if (r >= g && r >= b) 
		{
			h = 60 * (int)((g / 255 - b / 255) / delta) % 6;
		}
		else if (g >= r && g >= b) 
		{
			h = 60 * ((b / 255 - r / 255) / delta + 2);
		}
		else
		{
			h = 60 * ((r / 255 - g / 255) / delta + 4);
		}

		return { h , s * 100 , v };
	}

	if (c1 == "CMYK" && c2 == "RGB")
	{
		double c = numbers[0];
		double m = numbers[1];
		double y = numbers[2];
		double k = numbers[3];


		double r = 255 * (1. - c / 100) * (1. - k / 100);
		double g = 255 * (1. - m / 100) * (1. - k / 100);
		double b = 255 * (1. - y / 100) * (1. - k / 100);

		return { r, g, b };
	}

	if (c1 == "RGB" && c2 == "CMYK")
	{
		double r = numbers[0];
		double g = numbers[1];
		double b = numbers[2];

		double k = min(min(1. - (double)r / 255, 1. - (double)g / 255), 1. - (double)b / 255);
		if (1. - k == 0.)
		{
			return { 0, 0, 0, 100 };
		}

		double c = (1. - (double)r / 255 - k) / (1. - k);
		double m = (1. - (double)g / 255 - k) / (1. - k);
		double y = (1. - (double)b / 255 - k) / (1. - k);

		return { c * 100, m * 100, y * 100, k * 100 };
	}

	if (c1 == "XYZ" && c2 == "RGB")
	{
		double x = numbers[0];
		double y = numbers[1];
		double z = numbers[2];

		double Rn = 3.2406 * x / 100 - 1.5372 * y / 100 - 0.4986 * z / 100;
		double Gn = -0.9689 * x / 100 + 1.8758 * y / 100 + 0.0415 * z / 100;
		double Bn = 0.0557 * x / 100 - 0.2040 * y / 100 + 1.0570 * z / 100;

		return { NRGB(Rn) * 255, NRGB(Gn) * 255, NRGB(Bn) * 255 };
	}

	if (c2 == "XYZ" && c1 == "RGB")
	{
		double r = numbers[0];
		double g = numbers[1];
		double b = numbers[2];

		double Rn = NXYZ(r / 255) * 100;
		double Gn = NXYZ(g / 255) * 100;
		double Bn = NXYZ(b / 255) * 100;

		double X = 0.412453 * Rn + 0.357580 * Gn + 0.180423 * Bn;
		double Y = 0.212671 * Rn + 0.715160 * Gn + 0.072169 * Bn;
		double Z = 0.019334 * Rn + 0.119193 * Gn + 0.950227 * Bn;

		return { X, Y, Z };
	}

	if (c1 == "XYZ" && c2 == "LAB")
	{
		double xr = 0.9642;
		double yr = 1.0000;
		double zr = 0.8249;

		double x = numbers[0] / xr / 100;
		double y = numbers[1] / yr / 100;
		double z = numbers[2] / zr / 100;

		double l = 116 * FXYZ(y) - 16;
		double a = 500 * (FXYZ(x) - FXYZ(y));
		double b = 200 * (FXYZ(y) - FXYZ(z));

		return { l, a , b };
	}

	if (c1 == "LAB" && c2 == "XYZ")
	{
		double l = numbers[0];
		double a = numbers[1];
		double b = numbers[2];

		double fy = (l + 16) / 116;
		double fx = fy + (a / 500);
		double fz = fy - (b / 200);

		double Xr = 0.9642;
		double Yr = 1.0000;
		double Zr = 0.8249;

		double k = 903.3;
		double e = 0.008856;
		double x, y, z;

		if (fy > 6. / 29) 
		{
			y = fy * fy * fy * Yr;
		}
		else 
		{
			y = 3. / 29 * 3. / 29 * 3. / 29 * (116 * fy - 16) * Yr;
		}

		if (fx > 6. / 29)
		{
			x = fx * fx * fx * Xr;
		}
		else
		{
			x = 3. / 29 * 3. / 29 * 3. / 29 * (116 * fx - 16) * Xr;
		}

		if (fz > 6. / 29)
		{
			z = fz * fz * fz * Zr;
		}
		else
		{
			z = 3. / 29 * 3. / 29 * 3. / 29 * (116 * fz - 16) * Zr;
		}

		return { x * 100, y * 100, z * 100};
	}

	if (c1 == "RGB")
	{
		return calcColor("XYZ", c2, calcColor(c1, "XYZ", numbers));
	}

	if (c1 == "HSL" || c1 == "HSV" || c1 == "CMYK")
	{
		return calcColor("RGB", c2, calcColor(c1, "RGB", numbers));
	}

	if (c1 == "XYZ")
	{
		return calcColor("RGB", c2, calcColor(c1, "RGB", numbers));
	}

	if (c1 == "LAB")
	{
		return calcColor("XYZ", c2, calcColor(c1, "XYZ", numbers));
	}
}

Colors::Colors(QWidget *parent)
    : QWidget(parent)
{

	comboBox = new QComboBox(this);

	comboBox->addItem("RGB LAB CMYK");
	comboBox->addItem("RGB CMYK HSL");
	comboBox->addItem("RGB XYZ LAB");
	comboBox->addItem("RGB HSV LAB");
	comboBox->addItem("CMYK LAB HSV");
	comboBox->addItem("CMYK RGB HSL");

	comboBox->addItem("CMYK RGB HSV");
	comboBox->addItem("RGB XYZ HSL");
	comboBox->addItem("HSV XYZ LAB");
	comboBox->addItem("CMYK LAB RGB");
	comboBox->addItem("XYZ LAB HSL");
	comboBox->addItem("RGB XYZ HSL");

	comboBox->addItem("RGB XYZ CMYK");
	comboBox->addItem("CMYK LAB XYZ");
	comboBox->addItem("RGB CMYK HSV");
	comboBox->addItem("CMYK HSL LAB");
	comboBox->addItem("RGB HSL LAB");
	comboBox->addItem("CMYK XYZ RGB");

	comboBox->setCurrentIndex(0);

	connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onVariantChange(int)));

	//setupTabs({ "RGB", "LAB", "CMYK"});

    vl = new QVBoxLayout(this);
	hl1 = new QHBoxLayout(this);
	hl2 = new QHBoxLayout(this);

    vl->addLayout(hl1);
	vl->addLayout(hl2);

    ui.setupUi(this);
}

Colors::~Colors()
{}

void Colors::setupTabs(QList<QString> colors)
{
	ColorTab* c1 = new ColorTab(this, colors[0], 0);
	ColorTab* c2 = new ColorTab(this, colors[1], 1);
	ColorTab* c3 = new ColorTab(this, colors[2], 2);

	connect(c1, &ColorTab::colorChange, this, &Colors::processColorChange);
	connect(c2, &ColorTab::colorChange, this, &Colors::processColorChange);
	connect(c3, &ColorTab::colorChange, this, &Colors::processColorChange);

	hl2->addWidget(c1);
	hl2->addWidget(c2);
	hl2->addWidget(c3);

	for (int i = 0; i < tabs.size(); i++) 
	{
		tabs[i]->deleteLater();
	}

	tabs = { c1, c2, c3 };
}

void Colors::onVariantChange(int ind)
{
	QString txt = comboBox->currentText();

	QList<QString> colors = txt.split(" ");

	setupTabs(colors);
}

void Colors::processColorChange(int pos, int type) 
{
	QList<double> color;
	QList<double> colorRGB;
	if (type == 1) 
	{
		color = tabs[pos]->getButtonColor();
		color = calcColor("RGB", tabs[pos]->getColorName(), color);
		tabs[pos]->changeColor(color);
	}
	else
	{
		color = tabs[pos]->getColor();
		colorRGB = calcColor(tabs[pos]->getColorName(), "RGB", color);
		tabs[pos]->setBoxColor(colorRGB[0], colorRGB[1], colorRGB[2]);
	}
	QString c1 = tabs[0]->getColorName();
	QString c2 = tabs[1]->getColorName();
	QString c3 = tabs[2]->getColorName();
	if (pos == 0) 
	{
		color = calcColor(c1, c2, color);
		colorRGB = calcColor(tabs[1]->getColorName(), "RGB", color);
		tabs[1]->changeColor(color);
		tabs[1]->setBoxColor(colorRGB[0], colorRGB[1], colorRGB[2]);

		color = calcColor(c2, c3, color);
		colorRGB = calcColor(tabs[2]->getColorName(), "RGB", color);
		tabs[2]->changeColor(color);
		tabs[2]->setBoxColor(colorRGB[0], colorRGB[1], colorRGB[2]);
	}

	if (pos == 1) 
	{
		QList<double> left = calcColor(c2, c1, color);
		colorRGB = calcColor(tabs[0]->getColorName(), "RGB", left);
		tabs[0]->changeColor(left);
		tabs[0]->setBoxColor(colorRGB[0], colorRGB[1], colorRGB[2]);

		color = calcColor(c2, c3, color);
		colorRGB = calcColor(tabs[2]->getColorName(), "RGB", color);
		tabs[2]->changeColor(color);
		tabs[2]->setBoxColor(colorRGB[0], colorRGB[1], colorRGB[2]);
	}

	if (pos == 2) 
	{
		color = calcColor(c3, c2, color);
		colorRGB = calcColor(tabs[1]->getColorName(), "RGB", color);
		tabs[1]->changeColor(color);
		tabs[1]->setBoxColor(colorRGB[0], colorRGB[1], colorRGB[2]);

		color = calcColor(c2, c1, color);
		colorRGB = calcColor(tabs[0]->getColorName(), "RGB", color);
		tabs[0]->changeColor(color);
		tabs[0]->setBoxColor(colorRGB[0], colorRGB[1], colorRGB[2]);
	}
}