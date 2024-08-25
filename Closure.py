def find_closure(X, F):
    X_plus = set(X)  # Bắt đầu với tập hợp X

    # Lặp qua tập hợp F để tìm tập hợp X+
    while True:
        found_new_attribute = False

        # Lặp qua mỗi thuộc tính trong tập X
        for attribute in X:
            # Kiểm tra xem thuộc tính có thể được thêm vào X+ hay không
            if attribute not in X_plus and is_superfluous(X_plus.union({attribute}), X, F):
                X_plus.add(attribute)
                found_new_attribute = True

        # Nếu không có thuộc tính mới nào được thêm vào, kết thúc vòng lặp
        if not found_new_attribute:
            break

    return X_plus

def is_superfluous(candidate, X, F):
    # Kiểm tra xem candidate có là thuộc tính không cần thiết hay không
    for attribute in candidate:
        # Loại bỏ một thuộc tính và kiểm tra xem tập còn lại có thể tạo ra được bằng F không
        reduced_candidate = candidate - {attribute}
        if reduced_candidate != X and reduced_candidate not in F:
            return False
    return True

# Nhập tập thuộc tính X và tập phụ thuộc hàm F
X = input("Nhập tập thuộc tính X (các thuộc tính cách nhau bằng dấu phẩy): ").split(',')
F = input("Nhập tập phụ thuộc hàm F (mỗi phụ thuộc cách nhau bằng dấu phẩy): ").split(',')

# Chuyển đổi đầu vào thành tập hợp
X = set(map(str.strip, X))
F = set(map(str.strip, F))

# Tìm tập hợp X+
X_plus = find_closure(X, F)

# In kết quả
print("Tập X+ trên F là:", X_plus)
