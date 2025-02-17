# ����� ����������� ���� ��������
## ������
���� ��� ��������

$seg_1 = [s_1, e_1]$, $\quad$ $seg_2 = [s_2, e_2]$,

��� $s_i = (s_i^x, s_i^y, s_i^z)$, $\quad$ $e_i = (e_i^x, e_i^y, e_i^z)$

��������� ����������� ������� $Intersection : Segment3D \times Segment3D \rightarrow Vector3D$.

## �����������

��� **����������** ����������� $Intersection$ ����� ���������� ����� $(\infty, \infty, \infty)$.

���� ����������� - **�������**, �� ����� ������������ ���� �� ������� ����� ����� �������.

## �������
��������� � ���������� �������. � ����� ������� �������� �� 2 ����:
- **��������������**, ����� ����������� ������� � �������������� ����� �������� (��������, ������� �� ����� ���� �����)
- **��������������**, ����� ����������� ������� � ����������� ������� ������� ��� � ����� �������

� ������ �������, ���������� ������������ ������ ��������, � ������:
1. ��� �����
2. ����� � �������

��� ����� ����� �����������, ������ ���� ��� ���������. ��� ������ ��������.

������ ��������, ������� � �����. ����� ����������� �������, ���� ����� ���������� �� ������ ������� �� ����� ����� ����� ����� �������.

�����, ���������� ������� � ��������������� �����

$$
seg_1 = 
\begin{cases}
x = s_1^x + (e_1^x - s_1^x)t \\\\
y = s_1^y + (e_1^y - s_1^y)t \\\\
z = s_1^z + (e_1^z - s_1^z)t \\\\
\end{cases}
, t \in [0, 1]
$$

���������� ��� $seg_2$.

$$
seg_2 = 
\begin{cases}
x = s_2^x + (e_2^x - s_2^x)l \\\\
y = s_2^y + (e_2^y - s_2^y)l \\\\
z = s_2^z + (e_2^z - s_2^z)l \\\\
\end{cases}
, l \in [0, 1]
$$

����� ����� ����� �����������, ���������� ��� �������:

$$
\begin{cases}
s_1^x + (e_1^x - s_1^x)t = s_2^x + (e_2^x - s_2^x)l \\\\
s_1^y + (e_1^y - s_1^y)t = s_2^y + (e_2^y - s_2^y)l \\\\
s_1^z + (e_1^z - s_1^z)t = s_2^z + (e_2^z - s_2^z)l \\\\
\end{cases}
, t \in [0, 1], l \in [0, 1]
$$

��������� ������������ � ����������� ������, � ��������� ����� �������.

$$
\begin{cases}
(e_1^x - s_1^x)t - (e_2^x - s_2^x)l = s_2^x - s_1^x \\\\
(e_1^y - s_1^y)t - (e_2^y - s_2^y)l = s_2^y - s_1^y \\\\
(e_1^z - s_1^z)t - (e_2^z - s_2^z)l = s_2^z - s_1^z \\\\
\end{cases}
, t \in [0, 1], l \in [0, 1]
$$

������� ������������ ��� $t$ � $l$ �� $\alpha, \beta, \gamma$.

������� ������� ��������� � **�����** ����������� � **�����** ������������.

$$
\begin{cases}
\alpha_x t - \beta_x l = \gamma_x \\\\
\alpha_y t - \beta_y l = \gamma_y \\\\
\alpha_z t - \beta_z l = \gamma_z \\\\
\end{cases}
, t \in [0, 1], l \in [0, 1]
$$

�������� � ����

$$
\begin{cases}
\alpha_x t - \beta_x l = \gamma_x \\\\
0\cdot t - (\beta_y - \frac{\alpha_y}{\alpha_x} \beta_x)l = \gamma_y - \frac{\alpha_y}{\alpha_x}\gamma_x\\\\
0\cdot t  - (\beta_z - \frac{\alpha_z}{\alpha_x} \beta_x)l = \gamma_z - \frac{\alpha_z}{\alpha_x}\gamma_x\\\\
\end{cases}
, t \in [0, 1], l \in [0, 1]
$$

$$
\begin{cases}
\alpha_x t - \beta_x l = \gamma_x \\\\
l = -\frac{\gamma_y - \frac{\alpha_y}{\alpha_x}\gamma_x}{(\beta_y - \frac{\alpha_y}{\alpha_x} \beta_x)}\\\\
l = -\frac{\gamma_z - \frac{\alpha_z}{\alpha_x}\gamma_x}{(\beta_z - \frac{\alpha_z}{\alpha_x} \beta_x)}\\\\
\end{cases}
, t \in [0, 1], l \in [0, 1]
$$

������ ����� ����������� **��������������** �������.

��-������, ����� ���������, ����� �� ��������� ������� �� 0. ���� �����-�� �� ��������� � ����������� ����� 0, ����� ������������� ��� ������ �������� � ������ �������, �������� ��� �������.

� ����� �������, ���������� ����� ����������� ���� ��������, ��������� ���������� $t, l$ � ���� �� ��������� ��������.
