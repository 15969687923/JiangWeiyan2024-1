namespace 数据库课设
{
    partial class 进货提醒
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
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.gnoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gnameDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gclaDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gpDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.gamDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.pnoDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.商品表BindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.数据库课设DataSet3 = new 数据库课设.数据库课设DataSet3();
            this.商品表TableAdapter = new 数据库课设.数据库课设DataSet3TableAdapters.商品表TableAdapter();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.商品表BindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet3)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(185, 12);
            this.label1.TabIndex = 0;
            this.label1.Text = "以下商品不足10件，请尽快进货：";
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
            this.dataGridView1.Location = new System.Drawing.Point(13, 41);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowTemplate.Height = 23;
            this.dataGridView1.Size = new System.Drawing.Size(558, 208);
            this.dataGridView1.TabIndex = 1;
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
            this.商品表BindingSource.DataSource = this.数据库课设DataSet3;
            // 
            // 数据库课设DataSet3
            // 
            this.数据库课设DataSet3.DataSetName = "数据库课设DataSet3";
            this.数据库课设DataSet3.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // 商品表TableAdapter
            // 
            this.商品表TableAdapter.ClearBeforeFill = true;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(474, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(97, 33);
            this.button1.TabIndex = 2;
            this.button1.Text = "返回上级";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // tixing
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(586, 261);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.label1);
            this.Name = "tixing";
            this.Text = "tixing";
            this.Load += new System.EventHandler(this.tixing_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.商品表BindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.数据库课设DataSet3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private 数据库课设DataSet3 数据库课设DataSet3;
        private System.Windows.Forms.BindingSource 商品表BindingSource;
        private 数据库课设DataSet3TableAdapters.商品表TableAdapter 商品表TableAdapter;
        private System.Windows.Forms.DataGridViewTextBoxColumn gnoDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gnameDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gclaDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gpDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn gamDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn pnoDataGridViewTextBoxColumn;
        private System.Windows.Forms.Button button1;
    }
}