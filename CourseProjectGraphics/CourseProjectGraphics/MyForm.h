#pragma once

#include <iostream>

#include <vector>
#include "tgaimage.h"
#include "model.h"
#include "geometry.h"
#include "our_gl.h"

// ////////////////////////////////////////////////////////////////////
	Model *model = NULL;
	Model *model_1 = NULL;
	Model *model_2 = NULL; 
	Model *model_3 = NULL; 
	Model *model_4 = NULL; 
	Model *model_5 = NULL; 
	const int width = 600;
	const int height = 600;

	Vec3f light_dir(1, 1, 1);
	Vec3f       eye(0, 12, 1); //вид сверху
	//Vec3f       eye(-12, 12, 12); // изометрия сверху
	//Vec3f       eye(24, -6, -24); // чуть снизу изометрия
	//Vec3f       eye(-10, 10, 10); // изометрия сверху
	Vec3f    center(0, 0, 0);
	Vec3f        up(0, 1, 0);
	//Vec3f light_dir(1, 1, 1);
	//Vec3f       eye(-8, -7, -10);
	//Vec3f    center(0, 0, 0);
	//Vec3f        up(0, 2, 0);
	//Vec3f        up(0, 1, 1);
	struct GouraudShader : public IShader
	{
		Vec3f varying_intensity; // written by vertex shader, read by fragment shader
		mat<2, 3, float> varying_uv;        // same as above

		virtual Vec4f vertex(int iface, int nthvert)
		{
			Vec4f gl_Vertex = embed<4>(model_1->vert(iface, nthvert)); // read the vertex from .obj file
			gl_Vertex = Viewport * Projection*ModelView*gl_Vertex;     // transform it to screen coordinates
			varying_intensity[nthvert] = std::max(0.f, model_1->normal(iface, nthvert)*light_dir); // get diffuse lighting intensity
			return gl_Vertex;
		}

		virtual bool fragment(Vec3f bar, TGAColor &color)
		{
			float intensity = varying_intensity * bar;   // interpolate intensity for the current pixel
			if (intensity < 0.4)
				intensity = 0.4;
			color = TGAColor(255, 255, 255)*intensity; // well duh
			return false;                              // no, we do not discard this pixel
		}
	};

	struct GouraudShader_2 : public IShader
	{
		Vec3f varying_intensity; // written by vertex shader, read by fragment shader
		mat<2, 3, float> varying_uv;        // same as above

		virtual Vec4f vertex(int iface, int nthvert)
		{
			Vec4f gl_Vertex = embed<4>(model_2->vert(iface, nthvert)); // read the vertex from .obj file
			gl_Vertex = Viewport * Projection*ModelView*gl_Vertex;     // transform it to screen coordinates
			varying_intensity[nthvert] = std::max(0.f, model_2->normal(iface, nthvert)*light_dir); // get diffuse lighting intensity
			return gl_Vertex;
		}

		virtual bool fragment(Vec3f bar, TGAColor &color)
		{
			float intensity = varying_intensity * bar;   // interpolate intensity for the current pixel
			if (intensity < 0.4)
				intensity = 0.4;
			color = TGAColor(255, 255, 255)*intensity; // well duh
			return false;                              // no, we do not discard this pixel
		}
	};

	struct GouraudShader_3 : public IShader
	{
		Vec3f varying_intensity; // written by vertex shader, read by fragment shader
		mat<2, 3, float> varying_uv;        // same as above

		virtual Vec4f vertex(int iface, int nthvert)
		{
			Vec4f gl_Vertex = embed<4>(model_3->vert(iface, nthvert)); // read the vertex from .obj file
			gl_Vertex = Viewport * Projection*ModelView*gl_Vertex;     // transform it to screen coordinates
			varying_intensity[nthvert] = std::max(0.f, model_3->normal(iface, nthvert)*light_dir); // get diffuse lighting intensity
			return gl_Vertex;
		}

		virtual bool fragment(Vec3f bar, TGAColor &color)
		{
			float intensity = varying_intensity * bar;   // interpolate intensity for the current pixel
			color = TGAColor(155, 92, 105)*intensity; // well duh
			return false;                              // no, we do not discard this pixel
		}
	};

	struct GouraudShader_4 : public IShader
	{
		Vec3f varying_intensity; // written by vertex shader, read by fragment shader
		mat<2, 3, float> varying_uv;        // same as above

		virtual Vec4f vertex(int iface, int nthvert)
		{
			Vec4f gl_Vertex = embed<4>(model_4->vert(iface, nthvert)); // read the vertex from .obj file
			gl_Vertex = Viewport * Projection*ModelView*gl_Vertex;     // transform it to screen coordinates
			varying_intensity[nthvert] = std::max(0.f, model_4->normal(iface, nthvert)*light_dir); // get diffuse lighting intensity
			return gl_Vertex;
		}

		virtual bool fragment(Vec3f bar, TGAColor &color)
		{
			float intensity = varying_intensity * bar;   // interpolate intensity for the current pixel
			color = TGAColor(155, 92, 105)*intensity; // well duh
			return false;                              // no, we do not discard this pixel
		}
	};

	struct GouraudShader_5 : public IShader
	{
		Vec3f varying_intensity; // written by vertex shader, read by fragment shader
		mat<2, 3, float> varying_uv;        // same as above

		virtual Vec4f vertex(int iface, int nthvert)
		{
			Vec4f gl_Vertex = embed<4>(model_5->vert(iface, nthvert)); // read the vertex from .obj file
			gl_Vertex = Viewport * Projection*ModelView*gl_Vertex;     // transform it to screen coordinates
			varying_intensity[nthvert] = std::max(0.f, model_5->normal(iface, nthvert)*light_dir); // get diffuse lighting intensity
			return gl_Vertex;
		}

		virtual bool fragment(Vec3f bar, TGAColor &color)
		{
			float intensity = varying_intensity * bar;   // interpolate intensity for the current pixel
			color = TGAColor(82, 133, 182)*intensity; // well duh
			return false;                              // no, we do not discard this pixel
		}
	};

	GouraudShader shader;
	GouraudShader_2 shader_2;
	GouraudShader_3 shader_3;
	GouraudShader_4 shader_4;
	GouraudShader_5 shader_5;


	// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace CourseProjectGraphics
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;







	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 22);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Считать объекты из файлов";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 511);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(173, 23);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Построить сцену";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 78);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(162, 20);
			this->textBox1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 62);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Приращение по x:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 118);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Приращение по y:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(12, 134);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(162, 20);
			this->textBox2->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 179);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Приращение по z:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(12, 195);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(162, 20);
			this->textBox3->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 262);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Куда смотрим по x:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 326);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(105, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Куда смотрим по y:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(9, 394);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(105, 13);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Куда смотрим по z:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(12, 288);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(162, 20);
			this->textBox4->TabIndex = 14;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(12, 355);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(162, 20);
			this->textBox5->TabIndex = 15;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(12, 424);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(162, 20);
			this->textBox6->TabIndex = 16;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(425, 546);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Кнопка, отвечающая за инициализацию моделей данными из obj файлов
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int count = 0;
		model_1 = new Model("obj/room.obj");
		model_2 = new Model("obj/room.obj");
		model_3 = new Model("obj/chair.obj");
		model_4 = new Model("obj/room_try.obj");
		model_5 = new Model("obj/ball.obj");
		MessageBox::Show("Данные об объектах считаны");
	}

			 // Кнопка, отвечающая за прорисовку объектов на сцене
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// Считывание информации о положении камеры
		if (textBox1->Text != "")
			eye.x = eye.x + Convert::ToDouble(textBox1->Text);

		if (textBox2->Text != "")
			eye.y = eye.y + Convert::ToDouble(textBox2->Text);

		if (textBox3->Text != "")
			eye.z = eye.z + Convert::ToDouble(textBox3->Text);


		// Считывание информации о том, куда смотрим
		if (textBox4->Text != "")
			eye.x = Convert::ToDouble(textBox4->Text);

		if (textBox5->Text != "")
			eye.y = Convert::ToDouble(textBox5->Text);

		if (textBox6->Text != "")
			eye.z = Convert::ToDouble(textBox6->Text);

		lookat(eye, center, up);
		projection(-1.f / (eye - center).norm());
		light_dir.normalize();


		TGAImage image(width, height, TGAImage::RGB);
		TGAImage zbuffer(width, height, TGAImage::GRAYSCALE);


		// Прорисовка кресла
		viewport(width / 4, height / 9.9, width * 2 / 6, height * 2 / 6);
		for (int i = 0; i < model_3->nfaces(); i++)
		{
			Vec4f screen_coords[3];
			for (int j = 0; j < 3; j++)
			{
				screen_coords[j] = shader_3.vertex(i, j);
			}
			triangle(screen_coords, shader_3, image, zbuffer);
		}

		// Прорисовка первого кубика
		viewport(width / 20, height / 3.9, width * 1 / 6, height * 1 / 6);
		for (int i = 0; i < model_1->nfaces(); i++)
		{
			Vec4f screen_coords[3];
			for (int j = 0; j < 3; j++)
			{
				screen_coords[j] = shader.vertex(i, j);
			}
			triangle(screen_coords, shader, image, zbuffer);
		}

		// Прорисовка второго кубика
		viewport(width / 1.3, height / 3.9, width * 1 / 6, height * 1 / 6);
		for (int i = 0; i < model_2->nfaces(); i++)
		{
			Vec4f screen_coords[3];
			for (int j = 0; j < 3; j++)
			{
				screen_coords[j] = shader_2.vertex(i, j);
			}
			triangle(screen_coords, shader_2, image, zbuffer);
		}

		// Прорисовка шара 
		viewport(width / 1.3, height / 2.9, width * 1 / 6, height * 1 / 6);
		for (int i = 0; i < model_5->nfaces(); i++)
		{
			Vec4f screen_coords[3];
			for (int j = 0; j < 3; j++)
			{
				screen_coords[j] = shader_5.vertex(i, j);
			}
			triangle(screen_coords, shader_5, image, zbuffer);
		}

		
		/*
		// Прорисовка комнаты
		viewport(width / 10, height / 6, width * 12 / 6, height * 11 / 6);
		for (int i = 0; i < model_4->nfaces(); i++)
		{
			Vec4f screen_coords[3];
			for (int j = 0; j < 3; j++)
			{
				screen_coords[j] = shader_4.vertex(i, j);
			}
			triangle(screen_coords, shader_4, image, zbuffer);
		}

		*/

		image.flip_vertically(); // to place the origin in the bottom left corner of the image
		zbuffer.flip_vertically();
		image.write_tga_file("output.tga");
		zbuffer.write_tga_file("zbuffer.tga");
		
	}
	

};

	
}











