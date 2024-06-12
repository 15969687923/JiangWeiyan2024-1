namespace 数据库课设
{
    partial class 商品查询
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
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.gnoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gnameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gclaDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gpDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gamDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.pnoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.商品表BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.数据库课设DataSet2 = new 数据库课设.数据库课设DataSet2();
            this.数据库课设DataSet = new 数据库课设.数据库课设DataSet();
            this.商品表TableAdapter1 = new 数据库课设.数据库课设DataSetTableAdapters.商品表TableAdapter();
            this.tableAdapterManager = new 数据库课设.数据库课设DataSetTableAdapters.TableAdapterManager();
            this.商品表TableAdapter = new 数据库课设.数据库课设DataSet2TableAdapters.商品表TableAdapter();
            this.button3 = new System.Windows.Forms.Button();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.商品表BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 24);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "商品编号";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(167, 24);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 12);
            this.label2.TabIndex = 1;
            this.label2.Text = "商品名称";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(332, 24);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(53, 12);
            this.label3.TabIndex = 2;
            this.label3.Text = "商品类别";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(497, 24);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(65, 12);
            this.label4.TabIndex = 3;
            this.label4.Text = "供应商编号";
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(61, 21);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 21);
            this.textBox1.TabIndex = 4;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(226, 21);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(100, 21);
            this.textBox2.TabIndex = 5;
            // 
            // textBox3
            // 
            this.textBox3.Location = new System.Drawing.Point(391, 21);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(100, 21);
            this.textBox3.TabIndex = 6;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(566, 21);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(100, 21);
            this.textBox4.TabIndex = 7;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.textBox4);
            this.groupBox1.Controls.Add(this.button2);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.textBox3);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Controls.Add(this.textBox2);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.textBox1);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Location = new System.Drawing.Point(25, 27);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(666, 83);
            this.groupBox1.TabIndex = 8;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "查询方式";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(340, 48);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(298, 23);
            this.button2.TabIndex = 1;
            this.button2.Text = "重置";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(25, 48);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(301, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "查询";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AutoGenerateColumns = false;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.gnoDataGridViewTextBoxColumn,
            this.gnameDataGridViewTextBoxColumn,
            this.gclaDataGridViewTextBoxColumn,
            this.gpDataGridViewTextBoxColumn,
            this.gamDataGridViewTextBoxColumn,
            this.pnoDataGridViewTextBoxColumn});
            this.dataGridView1.DataSource = this.商品表BindingSource;
            this.dataGridView1.Location = new System.Drawing.Point(25, 116);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(666, 239);
            this.dataGridView1.TabIndex = 9;
            this.dataGridView1.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.dataGridView1_CellContentClick);
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
            // gclaDataGridViewTextBoxColumn
            // 
            this.gclaDataGridViewTextBoxColumn.DataPropertyName = "Gcla";
            this.gclaDataGridViewTextBoxColumn.HeaderText = "Gcla";
            this.gclaDataGridViewTextBoxColumn.Name = "gclaDataGridViewTextBoxColumn";
            // 
            // gpDataGridViewTextBoxColumn
            // 
            this.gpDataGridViewTextBoxColumn.DataPropertyName = "Gp";
            this.gpDataGridViewTextBoxColumn.HeaderText = "Gp";
            this.gpDataGridViewTextBoxColumn.Name = "gpDataGridViewTextBoxColumn";
            // 
            // gamDataGridViewTextBoxColumn
            // 
            this.gamDataGridViewTextBoxColumn.DataPropertyName = "Gam";
            this.gamDataGridViewTextBoxColumn.HeaderText = "Gam";
            this.gamDataGridViewTextBoxColumn.Name = "gamDataGridViewTextBoxColumn";
            // 
            // pnoDataGridViewTextBoxColumn
            // 
            this.pnoDataGridViewTextBoxColumn.DataPropertyName = "Pno";
            this.pnoDataGridViewTextBoxColumn.HeaderText = "Pno";
            this.pnoDataGridViewTextBoxColumn.Name = "pnoDataGridViewTextBoxColumn";
            // 
            // 商品表BindingSource
            // 
            this.商品表BindingSource.DataMember = "商品表";
            this.商品表BindingSource.DataSource = this.数据库课设DataSet2;
            // 
            // 数据库课设DataSet2
            // 
            this.数据库课设DataSet2.DataSetName = "数据库课设DataSet2";
            this.数据库课设DataSet2.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // 数据库课设DataSet
            // 
            this.数据库课设DataSet.DataSetName = "数据库课设DataSet";
            this.数据库课设DataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // 商品表TableAdapter1
            // 
            this.商品表TableAdapter1.ClearBeforeFill = true;
            // 
            // tableAdapterManager
            // 
            this.tableAdapterManager.BackupDataSetBeforeUpdate = false;
            this.tableAdapterManager.UpdateOrder = 数据库课设.数据库课设DataSetTableAdapters.TableAdapterManager.UpdateOrderOption.InsertUpdateDelete;
            this.tableAdapterManager.商品表TableAdapter = this.商品表TableAdapter1;
            // 
            // 商品表TableAdapter
            // 
            this.商品表TableAdapter.ClearBeforeFill = true;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(607, 13);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(75, 23);
            this.button3.TabIndex = 10;
            this.button3.Text = "返回上级";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // chaxun
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(722, 375);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.groupBox1);
            this.Name = "chaxun";
            this.Text = "chaxun";
            this.Load += new System.EventHandler(this.chaxun_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.商品表BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private 数据库课设DataSet2 数据库课设DataSet2;
        private System.Windows.Forms.BindingSource 商品表BindingSource;
        private 数据库课设DataSet2TableAdapters.商品表TableAdapter 商品表TableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn gnoDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gnameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gclaDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gpDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gamDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn pnoDataGridViewTextBoxColumn;
        private 数据库课设DataSet 数据库课设DataSet;
        private 数据库课设DataSetTableAdapters.商品表TableAdapter 商品表TableAdapter1;
        private 数据库课设DataSetTableAdapters.TableAdapterManager tableAdapterManager;
        private System.Windows.Forms.Button button3;
    }
}