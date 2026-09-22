sliding Window Pattern : Notes :---------------

Sliding window means maintaining a range:

[left ... right]

Instead of recalculating every subarray, we keep updating the same window.

When to use Sliding Window?

Use it when the problem asks about:

subarray / substring
continuous segment
longest / shortest / count
sum / frequency / distinct characters

Usually arrays or strings.

Pattern 1: Fixed Size Window

Window size is fixed, like k.

Example:

Maximum sum of subarray of size k

Idea:

Add right element
If window size > k:
    remove left element
Update answer when size == k

Template:

int left = 0;
int sum = 0;

for(int right = 0; right < n; right++) {
    sum += nums[right];

    if(right - left + 1 > k) {
        sum -= nums[left];
        left++;
    }

    if(right - left + 1 == k) {
        ans = max(ans, sum);
    }
}
Pattern 2: Variable Size Window

Window size changes based on condition.

Example:

Minimum size subarray sum >= target

Idea:

Expand right
While window is valid:
    update answer
    shrink left

Template:

int left = 0;
int sum = 0;
int ans = INT_MAX;

for(int right = 0; right < n; right++) {
    sum += nums[right];

    while(sum >= target) {
        ans = min(ans, right - left + 1);
        sum -= nums[left];
        left++;
    }
}
Pattern 3: Longest Valid Window

Example:

Longest substring without repeating characters

Idea:

Expand right
If invalid:
    shrink left until valid
Update max length

Template:

int left = 0;
int ans = 0;
unordered_map<char,int> freq;

for(int right = 0; right < s.size(); right++) {
    freq[s[right]]++;

    while(freq[s[right]] > 1) {
        freq[s[left]]--;
        left++;
    }

    ans = max(ans, right - left + 1);
}
Most Important Rule

For every sliding window problem, ask:

1. What is my window?
2. What makes the window valid?
3. When do I expand right?
4. When do I shrink left?
5. What answer do I update?
