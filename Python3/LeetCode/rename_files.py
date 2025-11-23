import os
import re

directory = "."

# 获取目录中的所有文件
files = [
    f
    for f in os.listdir(directory)
    if os.path.isfile(os.path.join(directory, f)) and f.endswith(".py")
]

# 遍历所有文件
for filename in files:
    # 提取文件名中的数字部分
    match = re.match(r"(\d+)\.(.+)\.py", filename)
    if match:
        number = match.group(1)
        name = match.group(2)

        # 格式化数字为4位，不足前面补0
        formatted_number = number.zfill(4)

        # 如果数字已经是4位，不需要重命名
        if len(number) != 4:
            new_filename = f"{formatted_number}.{name}.py"
            old_path = os.path.join(directory, filename)
            new_path = os.path.join(directory, new_filename)

            # 重命名文件
            os.rename(old_path, new_path)
            print(f"已将 {filename} 重命名为 {new_filename}")

print("所有文件重命名完成！")
