class Solution:
    def merge(self, nums1, m, nums2, n):
        # Step 1: Combine elements
        arr = nums1[:m] + nums2
        
        # Step 2: Heapify (Build Max Heap)
        def heapify(arr, n, i):
            largest = i
            left = 2 * i + 1
            right = 2 * i + 2
            
            if left < n and arr[left] > arr[largest]:
                largest = left
            
            if right < n and arr[right] > arr[largest]:
                largest = right
            
            if largest != i:
                arr[i], arr[largest] = arr[largest], arr[i]
                heapify(arr, n, largest)
        
        length = len(arr)
        
        # Build max heap
        for i in range(length // 2 - 1, -1, -1):
            heapify(arr, length, i)
        
        # Step 3: Heap Sort
        for i in range(length - 1, 0, -1):
            arr[0], arr[i] = arr[i], arr[0]
            heapify(arr, i, 0)
        
        # Step 4: Copy back into nums1
        for i in range(length):
            nums1[i] = arr[i]
