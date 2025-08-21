#pragma once
#include <ctime>
#include <cstdlib>

namespace Lab7 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MainForm : public System::Windows::Forms::Form
    {
    public:
        MainForm(void)
        {
            InitializeComponent();
            srand(time(NULL));
        }

    protected:
        ~MainForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::DataGridView^ dataGridView1;
    private: System::Windows::Forms::Button^ buttonGenerate;
    private: System::Windows::Forms::Label^ labelSum;
    private: System::Windows::Forms::TextBox^ textBoxN;

    private:
        System::ComponentModel::Container ^components;

        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->buttonGenerate = (gcnew System::Windows::Forms::Button());
            this->labelSum = (gcnew System::Windows::Forms::Label());
            this->textBoxN = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            //
            // dataGridView1
            //
            this->dataGridView1->Location = System::Drawing::Point(12, 50);
            this->dataGridView1->Size = System::Drawing::Size(400, 200);
            this->dataGridView1->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            //
            // buttonGenerate
            //
            this->buttonGenerate->Location = System::Drawing::Point(12, 12);
            this->buttonGenerate->Text = L"Сгенерировать массив";
            this->buttonGenerate->Click += gcnew System::EventHandler(this, &MainForm::buttonGenerate_Click);
            //
            // textBoxN
            //
            this->textBoxN->Location = System::Drawing::Point(200, 15);
            this->textBoxN->Width = 50;
            this->textBoxN->Text = L"5";
            //
            // labelSum
            //
            this->labelSum->Location = System::Drawing::Point(12, 270);
            this->labelSum->Text = L"Сумма: ";
            this->labelSum->AutoSize = true;
            //
            // MainForm
            //
            this->ClientSize = System::Drawing::Size(450, 320);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->buttonGenerate);
            this->Controls->Add(this->textBoxN);
            this->Controls->Add(this->labelSum);
            this->Text = L"ЛР №7";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private: System::Void buttonGenerate_Click(System::Object^ sender, System::EventArgs^ e) {
        int n = Convert::ToInt32(textBoxN->Text);
        if (n < 5 || n > 10) {
            MessageBox::Show("Введите число от 5 до 10");
            return;
        }

        dataGridView1->ColumnCount = n;
        dataGridView1->RowCount = n;

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = rand() % 100 - 50; // числа от -50 до 49
                dataGridView1->Rows[i]->Cells[j]->Value = val;
                sum += val;
            }
        }

        labelSum->Text = "Сумма: " + sum.ToString();
    }
    };
}
