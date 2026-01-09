#Concept-grasp

Think of a function like a box 📦
```
void dfs(int src, int dest, vector<int> &temp, ...)
```

The word temp here is just a LABEL stuck on the box.

Now you call it like this:
```
vector<int> tempPath;
dfs(src, dest, tempPath, paths, graph);
```

👉 tempPath is the real vector in memory
👉 temp is just the nickname used inside dfs

🚨 IMPORTANT:

Names do NOT have to match.

🔥 KEY IDEA (NEVER FORGET THIS)

Argument name ≠ Parameter name

They are independent names.

🧠 MEMORY DIAGRAM (SUPER IMPORTANT)
```
main():
   tempPath  ───────────────┐
                            │
dfs():
   temp   ──────────────────┘
```

Because you wrote:
```
vector<int> &temp
```

Both names point to the same memory.

❓ WHY & MATTERS HERE
If you wrote:
```
void dfs(..., vector<int> temp, ...)
```

Then:

A copy is created ❌

Changes inside dfs are lost

But you wrote:
```
vector<int> &temp
```

So:

No copy

Same vector

Changes persist ✅

🧪 SIMPLE PROOF (MENTAL)
```
vector<int> a;
dfs(a);

void dfs(vector<int> &b) {
    b.push_back(10);
}
```

After call:
```
a = {10}
```

Even though names are a and b.

🎯 REAL-LIFE ANALOGY

📱 You saved your friend’s number as:

On your phone: “Mom”

On his phone: “Rahul”

Same person. Different name.

🧑‍💻 C++ RULE (FORMAL)

Function parameters are local variable names that receive the argument’s value or reference.

🎯 INTERVIEW ONE-LINER (MEMORIZE)

“Argument names and parameter names don’t need to match; when passed by reference, both refer to the same object in memory.”

🧒 FINAL LOCK-IN SUMMARY

tempPath → name in caller

temp → name inside function

& → same memory

Name difference DOES NOT matter

Memory location matters

🚀 ONE SENTENCE TO NEVER FORGET

C++ passes memory, not variable names.