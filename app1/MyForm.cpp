#include "MyForm.h"
#include <Windows.h>
using namespace app1;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm);
	return 0;
}

//
// построение графика для каждого узла
//
System::Void app1::MyForm::построитьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Classifier cl;          // объект класса
	double c1, c2, x1, x2;  // коэф-ты для дискриминантной функции 
	double scale = 0.5;     // массштаб графика

	// очищаем график
	for (int i = 0; i < 6; i++) {
		this->chart1->Series[i]->Points->Clear();
	}

	// скрываем легенду для неиспользуемых параметров графика
	this->chart1->Series[2]->IsVisibleInLegend = 0;
	this->chart1->Series[3]->IsVisibleInLegend = 0;
	this->chart1->Series[5]->IsVisibleInLegend = 0;

	// 1-ый узел
	if (radioButton1->Checked) {
		this->chart1->ChartAreas[0]->AxisX->Title = "признак " + Convert::ToString(n1_pr1+1);
		this->chart1->ChartAreas[0]->AxisY->Title = "признак " + Convert::ToString(n1_pr2+1);

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(m1_cl1_pr1 + scale * (cl.cl_A[i][n1_pr1] - m1_cl1_pr1), m1_cl1_pr2 + scale * (cl.cl_A[i][n1_pr2] - m1_cl1_pr2)); // добавляем очередную точку класса А
			this->chart1->Series[0]->Points->AddXY(m1_cl1_pr1 + scale * (cl.cl_C[i][n1_pr1] - m1_cl1_pr1), m1_cl1_pr2 + scale * (cl.cl_C[i][n1_pr2] - m1_cl1_pr2)); // добавляем очередную точку класса C
			this->chart1->Series[1]->Points->AddXY(m1_cl2_pr1 + scale * (cl.cl_B[i][n1_pr1] - m1_cl2_pr1), m1_cl2_pr2 + scale * (cl.cl_B[i][n1_pr2] - m1_cl2_pr2)); // добавляем очередную точку класса B
			this->chart1->Series[1]->Points->AddXY(m1_cl2_pr1 + scale * (cl.cl_D[i][n1_pr1] - m1_cl2_pr1), m1_cl2_pr2 + scale * (cl.cl_D[i][n1_pr2] - m1_cl2_pr2)); // добавляем очередную точку класса D
			this->chart1->Series[0]->LegendText = "класс AC";
			this->chart1->Series[1]->LegendText = "класс BD";
			this->chart1->Series[0]->IsVisibleInLegend = 1;
			this->chart1->Series[1]->IsVisibleInLegend = 1;
		}

		// построение дискриминантной функции
		c1 = n1_c1;
		c2 = n1_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 20 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // добавляем очередную точку на график
		}
	}
	// 2-ой узел
	else if (radioButton2->Checked) {
		this->chart1->ChartAreas[0]->AxisX->Title = "признак " + Convert::ToString(n2_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "признак " + Convert::ToString(n2_pr2 + 1);

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(m2_cl1_pr1 + scale * (cl.cl_A[i][n2_pr1] - m2_cl1_pr1), m2_cl1_pr2 + scale * (cl.cl_A[i][n2_pr2] - m2_cl1_pr2)); // добавляем очередную точку класса A
			this->chart1->Series[1]->Points->AddXY(m2_cl2_pr1 + scale * (cl.cl_C[i][n2_pr1] - m2_cl2_pr1), m2_cl2_pr2 + scale * (cl.cl_C[i][n2_pr2] - m2_cl2_pr2)); // добавляем очередную точку класса C
			this->chart1->Series[0]->LegendText = "класс A";
			this->chart1->Series[1]->LegendText = "класс C";
		}

		// построение дискриминантной функции
		c1 = n2_c1;
		c2 = n2_c2;
		for (int i = 0; i < 2; i++) {
			//x2 = 40 * i + 20;
			x2 = 10 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // добавляем очередную точку на график
		}
	}
	// 3-ий узел
	else {
		this->chart1->ChartAreas[0]->AxisX->Title = "признак " + Convert::ToString(n3_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "признак " + Convert::ToString(n3_pr2 + 1);

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(m3_cl1_pr1 + scale * (cl.cl_B[i][n3_pr1] - m3_cl1_pr1), m3_cl1_pr2 + scale * (cl.cl_B[i][n3_pr2] - m3_cl1_pr2)); // добавляем очередную точку класса B
			this->chart1->Series[1]->Points->AddXY(m3_cl2_pr1 + scale * (cl.cl_D[i][n3_pr1] - m3_cl2_pr1), m3_cl2_pr2 + scale * (cl.cl_D[i][n3_pr2] - m3_cl2_pr2)); // добавляем очередную точку класса D
			this->chart1->Series[0]->LegendText = "класс B";
			this->chart1->Series[1]->LegendText = "класс D";
		}

		// построение дискриминантной функции
		c1 = n3_c1;
		c2 = n3_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 60 * i + 10;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // добавляем очередную точку на график
		}
	}

	return System::Void();
}

//
// очистка области построения графика для каждого узла
//
System::Void app1::MyForm::очиститьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	// очищаем график
	for (int i = 0; i < 6; i++) {
		this->chart1->Series[i]->Points->Clear();
	}

	return System::Void();
}

//
// выход из приложения
//
System::Void app1::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Вы точно хотите выйти?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

//
// запуск процедуры классификации объекта
//
System::Void app1::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	obj = new int[10];     // отводим память под хранение признаков объекта
	Classifier cl;         // объект класса
	double c1, c2, x1, x2; // параметры дискриминантной функции
	char res;              // результат распределения
	int pr1, pr2;          // номера тек. признаков
	double scale = 0.5;     // массштаб графика

	// инициализация нулевыми значениями (значения по умолчанию)
	for (int i = 0; i < 10; i++) {
		obj[i] = 0;
	}

	// заполнение массива введенными значениями
	try {
		if (textBox1->Text != "") {
			obj[0] = Convert::ToInt32(textBox1->Text);
		}
		if (textBox2->Text != "") {
			obj[1] = Convert::ToInt32(textBox2->Text);
		}
		if (textBox3->Text != "") {
			obj[2] = Convert::ToInt32(textBox3->Text);
		}
		if (textBox4->Text != "") {
			obj[3] = Convert::ToInt32(textBox4->Text);
		}
		if (textBox5->Text != "") {
			obj[4] = Convert::ToInt32(textBox5->Text);
		}
		if (textBox6->Text != "") {
			obj[5] = Convert::ToInt32(textBox6->Text);
		}
		if (textBox7->Text != "") {
			obj[6] = Convert::ToInt32(textBox7->Text);
		}
		if (textBox8->Text != "") {
			obj[7] = Convert::ToInt32(textBox8->Text);
		}
		if (textBox9->Text != "") {
			obj[8] = Convert::ToInt32(textBox9->Text);
		}
		if (textBox10->Text != "") {
			obj[9] = Convert::ToInt32(textBox10->Text);
		}
	}
	catch(...) {
		MessageBox::Show("Некорректный формат данных. Данные должны быть числами.", "Внимание!");
		return System::Void();
	}

	// очищаем график
	for (int i = 0; i < 6; i++) {
		this->chart1->Series[i]->Points->Clear();
	}

	// скрываем легенду для неиспользуемых параметров графика
	this->chart1->Series[2]->IsVisibleInLegend = 0;
	this->chart1->Series[3]->IsVisibleInLegend = 0;

	// отображаем легенду для скрытых ранее параметров графика
	this->chart1->Series[5]->IsVisibleInLegend = 1;

	res = cl.recognize(obj); // классификация
	
	// если объект класса A
	if (res == 'A') {
		this->label12->Text = "объект класса: A"; 
		this->chart1->ChartAreas[0]->AxisX->Title = "признак " + Convert::ToString(n2_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "признак " + Convert::ToString(n2_pr2 + 1);
		pr1 = n2_pr1;
		pr2 = n2_pr2;

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(m2_cl1_pr1 + scale * (cl.cl_A[i][n2_pr1] - m2_cl1_pr1), m2_cl1_pr2 + scale * (cl.cl_A[i][n2_pr2] - m2_cl1_pr2)); // добавляем очередную точку класса A
			this->chart1->Series[1]->Points->AddXY(m2_cl2_pr1 + scale * (cl.cl_C[i][n2_pr1] - m2_cl2_pr1), m2_cl2_pr2 + scale * (cl.cl_C[i][n2_pr2] - m2_cl2_pr2)); // добавляем очередную точку класса C
			this->chart1->Series[0]->LegendText = "класс A";
			this->chart1->Series[1]->LegendText = "класс C";
		}

		// построение дискриминантной функции
		c1 = n2_c1;
		c2 = n2_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 10 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // добавлем очередную точку
		}
	}
	// если объект класса B
	if (res == 'B') {
		this->label12->Text = "объект класса: B";
		this->chart1->ChartAreas[0]->AxisX->Title = "признак " + Convert::ToString(n3_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "признак " + Convert::ToString(n3_pr2 + 1);
		pr1 = n3_pr1;
		pr2 = n3_pr2;

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(m3_cl1_pr1 + scale * (cl.cl_B[i][n3_pr1] - m3_cl1_pr1), m3_cl1_pr2 + scale * (cl.cl_B[i][n3_pr2] - m3_cl1_pr2)); // добавляем очередную точку класса B
			this->chart1->Series[1]->Points->AddXY(m3_cl2_pr1 + scale * (cl.cl_D[i][n3_pr1] - m3_cl2_pr1), m3_cl2_pr2 + scale * (cl.cl_D[i][n3_pr2] - m3_cl2_pr2)); // добавляем очередную точку класса D
			this->chart1->Series[0]->LegendText = "класс B";
			this->chart1->Series[1]->LegendText = "класс D";
		}

		// построение дискриминантной функции
		c1 = n3_c1;
		c2 = n3_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 60 * i + 10;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // добавлем очередную точку
		}
	}
	// если объект класса C
	if (res == 'C') {
		this->label12->Text = "объект класса: C";
		this->chart1->ChartAreas[0]->AxisX->Title = "признак " + Convert::ToString(n2_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "признак " + Convert::ToString(n2_pr2 + 1);
		pr1 = n2_pr1;
		pr2 = n2_pr2;

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(m2_cl1_pr1 + scale * (cl.cl_A[i][n2_pr1] - m2_cl1_pr1), m2_cl1_pr2 + scale * (cl.cl_A[i][n2_pr2] - m2_cl1_pr2)); // добавляем очередную точку класса A
			this->chart1->Series[1]->Points->AddXY(m2_cl2_pr1 + scale * (cl.cl_C[i][n2_pr1] - m2_cl2_pr1), m2_cl2_pr2 + scale * (cl.cl_C[i][n2_pr2] - m2_cl2_pr2)); // добавляем очередную точку класса C
			this->chart1->Series[0]->LegendText = "класс A";
			this->chart1->Series[1]->LegendText = "класс C";
		}

		// построение дискриминантной функции
		c1 = n2_c1;
		c2 = n2_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 10 * i + 40;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // добавлем очередную точку
		}
	}
	// если объект класса D
	if (res == 'D') {
		this->label12->Text = "объект класса: D";
		this->chart1->ChartAreas[0]->AxisX->Title = "признак " + Convert::ToString(n3_pr1 + 1);
		this->chart1->ChartAreas[0]->AxisY->Title = "признак " + Convert::ToString(n3_pr2 + 1);
		pr1 = n3_pr1;
		pr2 = n3_pr2;

		for (int i = 0; i < 15; i++) {
			this->chart1->Series[0]->Points->AddXY(m3_cl1_pr1 + scale * (cl.cl_B[i][n3_pr1] - m3_cl1_pr1), m3_cl1_pr2 + scale * (cl.cl_B[i][n3_pr2] - m3_cl1_pr2)); // добавляем очередную точку класса B
			this->chart1->Series[1]->Points->AddXY(m3_cl2_pr1 + scale * (cl.cl_D[i][n3_pr1] - m3_cl2_pr1), m3_cl2_pr2 + scale * (cl.cl_D[i][n3_pr2] - m3_cl2_pr2)); // добавляем очередную точку класса D
			this->chart1->Series[0]->LegendText = "класс B";
			this->chart1->Series[1]->LegendText = "класс D";
		}

		// построение дискриминантной функции
		c1 = n3_c1;
		c2 = n3_c2;
		for (int i = 0; i < 2; i++) {
			x2 = 60 * i + 10;
			x1 = c1 - c2 * x2;
			this->chart1->Series[4]->Points->AddXY(x1, x2); // добавлем очередную точку
		}
	}

	// отображаем введенный объект
	this->chart1->Series[5]->Points->AddXY(obj[pr1], obj[pr2]);

	delete[] obj; // очищаем выделенную память

	return System::Void();
}

