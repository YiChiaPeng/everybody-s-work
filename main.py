
import pandas as pd
import scipy.stats as stats

from scipy.stats import chi2_contingency

file_path = 'Student2008.csv'  # 設定 CSV 文件的路徑
# 讀取一個CSV文件
df = pd.read_csv(file_path)

"""
semester       float64
gender          object
collegeYear     object
height         float64
weight         float64
hsGPA          float64
collegeGPA     float64
fincialAid      object
tvHours        float64
"""


df['hsGPA'] = df['hsGPA'].astype(float)
df['collegeGPA'] = df['collegeGPA'].astype(float)
df['fincialAid'] = df['fincialAid'].astype(str)

#本資料有些欄位缺失
# 僅對欄位  hsGPA,collegeGPA填補缺失值

# 使用平均值填充缺失值
df['hsGPA'] = df['hsGPA'].fillna(df['hsGPA'].mean())
df['collegeGPA'] = df['collegeGPA'].fillna(df['collegeGPA'].mean())




def calculate_correlation(column1, column2):
    
    
    
    
    # 提取指定欄位的數據
    data1 = df[column1]
    data2 = df[column2]
    
    # 計算相關係數
    correlation = data1.corr(data2)
    
    return correlation


def independent_t_test(data1, data2):
    t_statistic, p_value = stats.ttest_ind(data1, data2)
    return t_statistic, p_value

# 測試程式碼

column1="hsGPA"
column2="collegeGPA"
correlation = calculate_correlation( column1, column2)
print('\n1.')
print(f"The correlation coefficient between {column1} and {column2} is: {correlation}")

male_gpa =  df.loc[df['gender'] =='M', 'collegeGPA']# 男生的collegeGPA資料
female_gpa = df.loc[df['gender'] =='F', 'collegeGPA']# 女生的collegeGPA資料


t_statistic, p_value = independent_t_test(male_gpa, female_gpa)
print('\n3.')
print(f"T-Statistic: {t_statistic}")
print(f"P-Value: {p_value}")
# 檢查是否拒絕虛無假設
alpha = 0.05
print(f"alpha: {alpha}")
# 檢查是否拒絕虛無假設
if p_value < alpha:
    print("Reject the null hypothesis")
else:
    print("Fail to reject the null hypothesis")
    
    


# 創建示例 DataFrame

data = {'Gender': df["gender"],
        'Scholarship': df["fincialAid"]}
df = pd.DataFrame(data)

# 建立列聯表
cross_table = pd.crosstab(df['Gender'], df['Scholarship'])

# 執行卡方檢定
chi2, p_value, _, _ = chi2_contingency(cross_table)
print('\n7.')
# 顯示結果
print("Chi-square statistic:", chi2)
print("p-value:", p_value)

# 檢查是否拒絕虛無假設
alpha = 0.05

print(f"alpha: {alpha}")
if p_value < alpha:
    print("Reject the null hypothesis")
else:
    print("Fail to reject the null hypothesis")