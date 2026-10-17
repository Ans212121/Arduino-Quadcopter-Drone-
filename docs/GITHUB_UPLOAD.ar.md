# رفع المشروع على GitHub

## بيانات المستودع

**Repository name:** `Arduino-Quadcopter-Drone`

**Description:**

Arduino-based quadcopter hardware project documenting assembly, wiring, and ESC bench-test experiments.

**Topics:** `arduino`, `quadcopter`, `drone`, `embedded-systems`, `robotics`, `esc`, `cpp`

## خطوات الرفع من الكمبيوتر

1. فك ضغط الملف ZIP.
2. في GitHub اختر New repository.
3. اكتب اسم المستودع والوصف أعلاه، واختر Public إذا أردت ظهوره في ملفك الشخصي.
4. لا تضف README تلقائيًا لأن الملفات تتضمنه. اختر Create repository.
5. اختر uploading an existing file أو Add file ثم Upload files.
6. اسحب **محتويات** مجلد Arduino-Quadcopter-Drone إلى صفحة الرفع مع مجلداتها. يجب أن يكون README.md في جذر المستودع، دون مجلد خارجي إضافي.
7. اكتب رسالة الحفظ: `Add drone project documentation and ESC bench-test example` ثم احفظ التغييرات.
8. تأكد أن README يعرض الصور الثلاث وأن مسارات firmware وdocs موجودة. لا ترفع ملف ZIP وحده إذا أردت استعراض الملفات والكود.
9. من About أضف الوصف والموضوعات، ومن ملفك الشخصي استخدم Customize your pins لتثبيت المشروع.

## بديل باستخدام Git

نفّذ من داخل مجلد المشروع، واستبدل YOUR_USERNAME باسم حسابك وREPOSITORY_URL برابط المستودع الذي أنشأته. لا تنشئ README على GitHub قبل هذه الخطوات.

```bash
git init
git add .
git commit -m "Add drone project documentation and ESC bench-test example"
git branch -M main
git remote add origin REPOSITORY_URL
git push -u origin main
```

## وصف مختصر لملفك الشخصي

**العربي:** مشروع درون رباعي يوثّق تجميع الهيكل والتوصيلات والعمل البرمجي باستخدام Arduino، مع مثال لاختبار وحدات التحكم بسرعة المحركات ESC.

**English:** Quadcopter hardware project documenting frame assembly, wiring, and Arduino programming, with an example for ESC motor bench testing.

لا تنسب للمشروع طيرانًا ذاتيًا أو ذكاءً اصطناعيًا أو نتائج أداء إلا بعد تنفيذها وتوثيقها فعليًا. إذا كان المشروع جماعيًا فأضف أسماء المشاركين وأدوارهم الصحيحة قبل النشر. لم تُضف رخصة تلقائيًا؛ اخترها بعد التأكد من ملكية العمل.

المصدر: https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository
