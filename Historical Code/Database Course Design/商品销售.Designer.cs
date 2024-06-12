namespace 数据库课设
{
    partial class 商品销售
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.label1 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.dateTimePicker1 = new System.Windows.Forms.DateTimePicker();
            this.数据库课设DataSet = new 数据库课设.数据库课设DataSet();
            this.商品表BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.商品表TableAdapter = new 数据库课设.数据库课设DataSetTableAdapters.商品表TableAdapter();
            this.数据库课设DataSet1 = new 数据库课设.数据库课设DataSet1();
            this.出售商品表BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.出售商品表TableAdapter = new 数据库课设.数据库课设DataSet1TableAdapters.出售商品表TableAdapter();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.sellnumDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gnoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gnameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gpDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.amountDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.smonedyDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.selldateDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.snoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.商品表BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.出售商品表BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(12, 15);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "销售单号";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(71, 12);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 21);
            this.textBox1.TabIndex = 1;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 54);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 2;
            this.label2.Text = "商品编号";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(12, 90);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 3;
            this.label3.Text = "商品名称";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(201, 15);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(53, 12);
            this.label4.TabIndex = 4;
            this.label4.Text = "销售数量";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(201, 54);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(53, 12);
            this.label5.TabIndex = 5;
            this.label5.Text = "销售价格";
            this.label5.Click += new System.EventHandler(this.label5_Click);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(201, 90);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(53, 12);
            this.label6.TabIndex = 6;
            this.label6.Text = "销售日期";
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(71, 51);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 21);
            this.textBox2.TabIndex = 7;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(71, 87);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 21);
            this.textBox3.TabIndex = 8;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(260, 12);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(109, 21);
            this.textBox4.TabIndex = 9;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(260, 51);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(109, 21);
            this.textBox5.TabIndex = 10;
            // 
            // dateTimePicker1
            // 
            this.dateTimePicker1.Location = new System.Drawing.Point(260, 87);
            this.dateTimePicker1.Name = "dateTimePicker1";
            this.dateTimePicker1.Size = new System.Drawing.Size(109, 21);
            this.dateTimePicker1.TabIndex = 12;
            // 
            // 数据库课设DataSet
            // 
            this.数据库课设DataSet.DataSetName = "数据库课设DataSet";
            this.数据库课设DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // 商品表BindingSource
            // 
            this.商品表BindingSource.DataMember = "商品表";
            this.商品表BindingSource.DataSource = this.数据库课设DataSet;
            // 
            // 商品表TableAdapter
            // 
            this.商品表TableAdapter.ClearBeforeFill = true;
            // 
            // 数据库课设DataSet1
            // 
            this.数据库课设DataSet1.DataSetName = "数据库课设DataSet1";
            this.数据库课设DataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // 出售商品表BindingSource
            // 
            this.出售商品表BindingSource.DataMember = "出售商品表";
            this.出售商品表BindingSource.DataSource = this.数据库课设DataSet1;
            // 
            // 出售商品表TableAdapter
            // 
            this.出售商品表TableAdapter.ClearBeforeFill = true;
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.sellnumDataGridViewTextBoxColumn,
            this.gnoDataGridViewTextBoxColumn,
            this.gnameDataGridViewTextBoxColumn,
            this.gpDataGridViewTextBoxColumn,
            this.amountDataGridViewTextBoxColumn,
            this.smonedyDataGridViewTextBoxColumn,
            this.selldateDataGridViewTextBoxColumn,
            this.snoDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.出售商品表BindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(14, 126);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(755, 271);
            this.dataGridView1.TabIndex = 13;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick_1);
            // 
            // sellnumDataGridViewTextBoxColumn
            // 
            this.sellnumDataGridViewTextBoxColumn.DataPropertyName = "Sellnum";
            this.sellnumDataGridViewTextBoxColumn.HeaderText = "Sellnum";
            this.sellnumDataGridViewTextBoxColumn.Name = "sellnumDataGridViewTextBoxColumn";
            // 
            // gnoDataGridViewTextBoxColumn
            // 
            this.gnoDataGridViewTextBoxColumn.DataPropertyName = "Gno";
            this.gnoDataGridViewTextBoxColumn.HeaderText = "Gno";
            this.gnoDataGridViewTextBoxColumn.Name = "gnoDataGridViewTextBoxColumn";
            // 
            // gnameDataGridViewTextBoxColumn
            // 
            this.gnameDataGridViewTextBoxColumn.DataPropertyName = "Gname";
            this.gnameDataGridViewTextBoxColumn.HeaderText = "Gname";
            this.gnameDataGridViewTextBoxColumn.Name = "gnameDataGridViewTextBoxColumn";
            // 
            // gpDataGridViewTextBoxColumn
            // 
            this.gpDataGridViewTextBoxColumn.DataPropertyName = "Gp";
            this.gpDataGridViewTextBoxColumn.HeaderText = "Gp";
            this.gpDataGridViewTextBoxColumn.Name = "gpDataGridViewTextBoxColumn";
            // 
            // amountDataGridViewTextBoxColumn
            // 
            this.amountDataGridViewTextBoxColumn.DataPropertyName = "Amount";
            this.amountDataGridViewTextBoxColumn.HeaderText = "Amount";
            this.amountDataGridViewTextBoxColumn.Name = "amountDataGridViewTextBoxColumn";
            // 
            // smonedyDataGridViewTextBoxColumn
            // 
            this.smonedyDataGridViewTextBoxColumn.DataPropertyName = "Smonedy";
            this.smonedyDataGridViewTextBoxColumn.HeaderText = "Smonedy";
            this.smonedyDataGridViewTextBoxColumn.Name = "smonedyDataGridViewTextBoxColumn";
            // 
            // selldateDataGridViewTextBoxColumn
            // 
            this.selldateDataGridViewTextBoxColumn.DataPropertyName = "Selldate";
            this.selldateDataGridViewTextBoxColumn.HeaderText = "Selldate";
            this.selldateDataGridViewTextBoxColumn.Name = "selldateDataGridViewTextBoxColumn";
            // 
            // snoDataGridViewTextBoxColumn
            // 
            this.snoDataGridViewTextBoxColumn.DataPropertyName = "Sno";
            this.snoDataGridViewTextBoxColumn.HeaderText = "Sno";
            this.snoDataGridViewTextBoxColumn.Name = "snoDataGridViewTextBoxColumn";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(577, 13);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 15;
            this.button2.Text = "重置";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(472, 13);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 16;
            this.button1.Text = "销售";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(472, 48);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(180, 24);
            this.button3.TabIndex = 17;
            this.button3.Text = "返回上级";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // xiaoshou
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(781, 409);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.dateTimePicker1);
            this.Controls.Add(this.textBox5);
            this.Controls.Add(this.textBox4);
            this.Controls.Add(this.textBox3);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.label1);
            this.Name = "xiaoshou";
            this.Text = "xiaoshou";
            this.Load += new System.EventHandler(this.xiaoshou_Load);
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.商品表BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.出售商品表BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.DateTimePicker dateTimePicker1;
        private 数据库课设DataSet 数据库课设DataSet;
        private System.Windows.Forms.BindingSource 商品表BindingSource;
        private 数据库课设DataSetTableAdapters.商品表TableAdapter 商品表TableAdapter;
        private 数据库课设DataSet1 数据库课设DataSet1;
        private System.Windows.Forms.BindingSource 出售商品表BindingSource;
        private 数据库课设DataSet1TableAdapters.出售商品表TableAdapter 出售商品表TableAdapter;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn sellnumDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gnoDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gnameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gpDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn amountDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn smonedyDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn selldateDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn snoDataGridViewTextBoxColumn;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button3;
    }
}