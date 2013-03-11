== Giới thiệu về gcs ==

gcs là từ viết tắt của GSS Control Station.
Đây là ứng dụng được sử dụng trong dự án GSS-Hệ thống robot phun thuốc BVTV cho hoa.
Ứng dụng là công cụ để vận hành từ xa(Remote control), thiết lập cấu hình thiết bị và sử dụng để kiểm tra, hỗ trợ trong lập trình điều khiển

Ứng dụng được điều chỉnh để viết trên Qt5 và Qt Creator 2.6.
Các thay đổi để chuyển đổi từ Qt4 -> Qt5:
 - Bỏ QtGui trong các khai báo include của file cũ
 - Trong .pro file thêm vào: greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
